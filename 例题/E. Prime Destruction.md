# [[0]]

> **原题链接:** (https://codeforces.com/contest/2266/problem/E)

**涉及知识点:** [[埃氏筛]], [[]]，[[补题]],[[]],[[]]

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

constexpr int MAX_N = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // primeDivisors[x]：x 的所有不同质因数
    vector<vector<int>> primeDivisors(MAX_N + 1);

    for (int p = 2; p <= MAX_N; ++p) {
        if (primeDivisors[p].empty()) {  // p 是质数
            for (int multiple = p; multiple <= MAX_N; multiple += p) {
                primeDivisors[multiple].push_back(p);
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> dp(n + 1, 0);

        for (int x = k + 1; x <= n; ++x) {
            dp[x] = LLONG_MAX;

            for (int p : primeDivisors[x]) {
                dp[x] = min(
                    dp[x],
                    1LL + 1LL * p * dp[x / p]
                );
            }
        }

        long long answer = 0;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            answer += dp[x];
        }

        cout << answer << '\n';
    }

    return 0;
} 
```

---


