# [[0]]

> **原题链接:** (https://codeforces.com/contest/2246/problem/D)

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

// 单个正整数独立清零所需的操作次数。
// 31 - __builtin_clz(x) 等于二进制位数减一。
int clear_cost(unsigned int x) {
    return __builtin_popcount(x) + 31 - __builtin_clz(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int mx = 0;

        for (int &x : a) {
            cin >> x;
            mx = max(mx, x);
        }

        int max_k = 0;
        while ((1 << max_k) < mx) {
            ++max_k;
        }

        long long answer = LLONG_MAX;

        // 枚举整个数组一起除以 2 的次数。
        for (int k = 0; k <= max_k; ++k) {
            int step = 1 << k;
            long long total = k;

            for (int x : a) {
                // 不小于 x 的最小的 2^k 的倍数。
                int c = (x + step - 1) / step * step;
                int best = INT_MAX;

                // 枚举最终目标值 b。
                for (int b = c; b <= c + 32; b += step) {
                    // 初始自增次数 + 整批除法后的单独清零次数。
                    int cost = (b - x) + clear_cost(b / step);
                    best = min(best, cost);
                }

                total += best;
            }

            answer = min(answer, total);
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---


