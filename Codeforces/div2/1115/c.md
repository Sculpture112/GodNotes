# []

> **原题链接:** ()

**涉及知识点:** [[贪心算法]], [[树状数组]]，[[补题]],[[优先队列]],[[已AC]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

```cpp
优先队列
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for (ll &x : v) cin >> x;

    // 使用一维数组，避免 n 很大、m 很小时产生大量 vector 对象。
    vector<ll> a(1LL * n * m);
    for (ll &x : a) cin >> x;

    // 拆空任意一行需要 m 块，因此答案至多是 m。
    int ans = m;

    // 维护当前后缀中最大的 ans - 1 个数。
    priority_queue<ll, vector<ll>, greater<ll>> heap;
    ll sum = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            ll x = a[1LL * i * m + j];

            heap.push(x);
            sum += x;

            // 只保留最大的 ans - 1 个数。
            if ((int)heap.size() == ans) {
                sum -= heap.top();
                heap.pop();
            }
        }

        // 当前保留的棋块已经足以击垮第 i 层。
        while (!heap.empty() && sum >= v[i]) {
            ans = (int)heap.size();
			// 这里能知道弹出去的就一定不是最优,因为此处sum>=v[i],如果需要ans变小,必须要有一个更大的值加入  
            // 尝试再少选一个：删除当前选择中最小的数。
            sum -= heap.top();
            heap.pop();
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}

```




```cpp
这个是用mutiset做
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 4'000'000'000'000'000'000LL;
#define all(x) (x).begin(), (x).end()
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (ll &x : v) cin >> x;
    vector<ll> a(1LL * n * m);
    for (ll &x : a) cin >> x;
    ll ans = m;
    multiset<ll> best;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            best.insert(a[1LL * i * m + j]);
            if ((int)best.size() > m) {
                best.erase(best.begin());
            }
        }
        ll sum = 0;
        ll cnt = 0;
        for (auto it = best.rbegin(); it != best.rend(); ++it) {
            sum += *it;
            ++cnt;
            if (sum >= v[i]) {
                ans = min(ans, cnt);
                break;
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 4'000'000'000'000'000'000LL;
#define all(x) (x).begin(), (x).end()
struct Fenwick
{
    int n;
    vector<ll> tree;
    Fenwick(int n) : n(n), tree(n + 1) {}
    void add(int x, ll value)
    {
        for (; x <= n; x += x & -x)
        {
            tree[x] += value;
        }
    }
    ll sum(int x) const
    {
        ll result = 0;
        for (; x > 0; x -= x & -x)
        {
            result += tree[x];
        }
        return result;
    }
    // 返回第一个前缀和 >= target 的位置
    int lower_bound(ll target) const
    {
        int position = 0;
        ll prefix = 0;
        int step = 1;
        while ((step << 1) <= n)
            step <<= 1;
        for (; step > 0; step >>= 1)
        {
            int next = position + step;
            if (next <= n && prefix + tree[next] < target)
            {
                position = next;
                prefix += tree[next];
            }
        }
        return position + 1;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> stability(n);
    for (ll &x : stability)
        cin >> x;
    vector<ll> damage(1LL * n * m);
    vector<ll> values(1LL * n * m);
    for (int i = 0; i < n * m; ++i)
    {
        cin >> damage[i];
        values[i] = damage[i];
    }
    // 降序离散化：树状数组前缀代表较大的伤害值
    sort(all(values), greater<ll>());
    values.erase(unique(all(values)), values.end());
    Fenwick count_bit(values.size());
    Fenwick sum_bit(values.size());
    ll answer = m;
    for (int i = n - 1; i >= 0; --i)
    {
        // 加入第 i 行，当前数据结构包含第 i..n 行
        for (int j = 0; j < m; ++j)
        {
            ll x = damage[1LL * i * m + j];
            int position =
                lower_bound(all(values), x, greater<ll>()) - values.begin() + 1;
            count_bit.add(position, 1);
            sum_bit.add(position, x);
        }
        // 即使取完当前后缀也无法破坏第 i 层
        if (sum_bit.sum(values.size()) < stability[i])
        {
            continue;
        }
        int position = sum_bit.lower_bound(stability[i]);
        ll damage_before = sum_bit.sum(position - 1);
        ll pieces_before = count_bit.sum(position - 1);
        ll remaining = stability[i] - damage_before;
        ll current_damage = values[position - 1];
        ll pieces_here =
            (remaining + current_damage - 1) / current_damage;
        answer = min(answer, pieces_before + pieces_here);
    }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
```

---


