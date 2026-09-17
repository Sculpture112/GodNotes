# []

> **原题链接:** (https://codeforces.com/contest/2257/problem/D)

**涉及知识点:** [[数论]], [[前缀和]]，[[补题]],[[二分查找]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

**触发条件：**

**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll S;
        int q;
        cin >> S >> q;

        vector<ll> small, large;

        for (ll i = 1; i * i <= S; ++i) {
            if (S % i == 0) {
                small.push_back(i);
                if (i != S / i) {
                    large.push_back(S / i);
                }
            }
        }

        // 小因数递增，大因数倒序后递增，无需排序。
        vector<ll> d;
        d.reserve(1 + small.size() + large.size());
        d.push_back(0);

        for (ll v : small) d.push_back(v);
        for (auto it = large.rbegin(); it != large.rend(); ++it) {
            d.push_back(*it);
        }

        int m = static_cast<int>(d.size()) - 1;

        // pref[i]：前 d[i] 列的完整阶梯面积。
        vector<ll> pref(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            pref[i] = pref[i - 1]
                    + (d[i] - d[i - 1]) * (S / d[i]);
        }

        while (q--) {
            ll x, y;
            cin >> x >> y;

            // 高度至少为 y 的阶梯，其最右端为 d[k]。
            int k = static_cast<int>(
                upper_bound(d.begin() + 1, d.end(), S / y)
                - d.begin()
            ) - 1;

            if (x <= d[k]) {
                // 此时整个查询矩形均被覆盖，且 x*y <= S。
                cout << x * y << '\n';
                continue;
            }

            // x 位于第 j 段阶梯内。
            int j = static_cast<int>(
                lower_bound(d.begin() + 1, d.end(), x)
                - d.begin()
            );

            ll areaX = pref[j - 1]
                     + (x - d[j - 1]) * (S / d[j]);

            ll answer = d[k] * y + areaX - pref[k];
            cout << answer << '\n';
        }
    }

    return 0;
}
```

---


