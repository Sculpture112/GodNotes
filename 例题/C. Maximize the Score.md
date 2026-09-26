# [[0]]

> **原题链接:** (https://codeforces.com/contest/2248/problem/C)

**涉及知识点:** [[DP]], [[]]，[[补题]],[[]],[[]]

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

void solve() {
    int n;
    cin >> n;

    int m = 2 * n;

    // first[x] 表示 x 第一次出现的位置
    vector<int> first(n + 1, 0);

    // dp[i] 表示清空原数组前 i 个位置的最大得分
    vector<ll> dp(m + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;

        // 将当前位置单独删除
        dp[i] = dp[i - 1] + 1;

        if (first[x] == 0) {
            first[x] = i;
        } else {
            int l = first[x];
            ll len = i - l + 1LL;

            // 将区间 [l, i] 一次性删除
            dp[i] = max(dp[i],
                        dp[l - 1] + len * len);
        }
    }

    cout << dp[m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
```

---


