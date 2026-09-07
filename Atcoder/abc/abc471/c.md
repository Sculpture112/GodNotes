# []

> **原题链接:** ()

**涉及知识点:** [[贪心算法]], [[双指针]]，[[补题]],[[]],[[平衡树]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int64> A(N);
    for (auto &x : A) cin >> x;

    sort(A.begin(), A.end());

    int pos = lower_bound(A.begin(), A.end(), 0LL) - A.begin();

    int l, r;
    int64 cur = 0;
    int64 ans = 0;

    // 第一次从 0 出发
    if (pos == 0) {
        // 全部为正数
        l = r = 0;
        cur = A[0];
    } else if (pos == N) {
        // 全部为负数
        l = r = N - 1;
        cur = A[N - 1];
    } else {
        int left = pos - 1;
        int right = pos;

        if (llabs(A[left]) <= llabs(A[right])) {
            l = r = left;
            cur = A[left];
        } else {
            l = r = right;
            cur = A[right];
        }
    }

    ans += llabs(cur);

    // 继续向左右扩张
    for (int step = 1; step < N; ++step) {
        int64 leftDist = (l > 0 ? llabs(cur - A[l - 1]) : (1LL << 62));
        int64 rightDist = (r + 1 < N ? llabs(A[r + 1] - cur) : (1LL << 62));

        // 相等时选坐标较小的左边点
        if (leftDist <= rightDist) {
            --l;
            cur = A[l];
            ans += leftDist;
        } else {
            ++r;
            cur = A[r];
            ans += rightDist;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    set<ll> cookies;

    for (int i = 0; i < N; ++i) {
        ll x;
        cin >> x;
        cookies.insert(x);
    }

    ll cur = 0;
    ll answer = 0;

    while (!cookies.empty()) {
        // 第一个 >= cur 的剩余坐标
        auto right = cookies.lower_bound(cur);

        auto chosen = cookies.end();

        if (right == cookies.begin()) {
            // 左边没有剩余饼干，只能选择右边
            chosen = right;
        } else if (right == cookies.end()) {
            // 右边没有剩余饼干，只能选择左边
            chosen = prev(right);
        } else {
            // 左右两边都有饼干
            auto left = prev(right);

            ll leftDistance = llabs(cur - *left);
            ll rightDistance = llabs(*right - cur);

            // 距离相等时选择坐标更小的左侧点
            if (leftDistance <= rightDistance) {
                chosen = left;
            } else {
                chosen = right;
            }
        }

        answer += llabs(cur - *chosen);
        cur = *chosen;

        // 捡起后从集合中删除
        cookies.erase(chosen);
    }

    cout << answer << '\n';

    return 0;
}
```
