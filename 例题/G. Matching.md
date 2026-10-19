# [[0]]

> **原题链接:** (https://codeforces.com/gym/104417/problem/G)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        // first：分组依据 i - a[i]，second：点权 a[i]
        vector<pair<long long, long long>> v(n);
        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;
            v[i - 1] = {i - x, x};
        }

        sort(v.begin(), v.end(), [](const auto& x, const auto& y) {
            if (x.first != y.first)
                return x.first < y.first;
            return x.second > y.second;
        });

        long long ans = 0;

        for (int l = 0; l < n; ) {
            int r = l + 1;
            while (r < n && v[r].first == v[l].first)
                ++r;

            // 当前组为 [l, r)，每次选剩余最大的两个点权
            for (int i = l; i + 1 < r; i += 2) {
                long long sum = v[i].second + v[i + 1].second;
                if (sum <= 0)
                    break;
                ans += sum;
            }

            l = r;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---


