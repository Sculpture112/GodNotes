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