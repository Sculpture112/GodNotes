# [[0]]

> **原题链接:** (https://codeforces.com/problemset/problem/1111/D)

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

constexpr int MOD = 1000000007;

int id(char ch) {
    if ('a' <= ch && ch <= 'z') return ch - 'a';
    return ch - 'A' + 26;
}

int modpow(int a, int e) {
    long long res = 1, base = a;
    while (e) {
        if (e & 1) res = res * base % MOD;
        base = base * base % MOD;
        e >>= 1;
    }
    return (int)res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size(), half = n / 2;

    array<int, 52> cnt{};
    for (char ch : s) ++cnt[id(ch)];

    vector<int> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;

    invfac[n] = modpow(fac[n], MOD - 2);
    for (int i = n; i >= 1; --i)
        invfac[i - 1] = 1LL * invfac[i] * i % MOD;

    long long arrange = 1LL * fac[half] * fac[half] % MOD;
    for (int c : cnt)
        arrange = arrange * invfac[c] % MOD;

    vector<int> dp(half + 1);
    dp[0] = 1;
    for (int c : cnt) {
        if (c == 0 || c > half) continue;
        for (int k = half; k >= c; --k) {
            dp[k] += dp[k - c];
            if (dp[k] >= MOD) dp[k] -= MOD;
        }
    }

    int ans[52][52]{};
    for (int i = 0; i < 52; ++i)
        ans[i][i] = dp[half];

    for (int i = 0; i < 52; ++i) {
        if (cnt[i] == 0) continue;

        vector<int> without_i = dp;
        for (int k = cnt[i]; k <= half; ++k) {
            without_i[k] -= without_i[k - cnt[i]];
            if (without_i[k] < 0) without_i[k] += MOD;
        }

        for (int j = i + 1; j < 52; ++j) {
            if (cnt[j] == 0 || cnt[i] + cnt[j] > half) continue;

            int ways = 0;
            bool add = true;
            for (int k = half; k >= 0; k -= cnt[j]) {
                if (add) {
                    ways += without_i[k];
                    if (ways >= MOD) ways -= MOD;
                } else {
                    ways -= without_i[k];
                    if (ways < 0) ways += MOD;
                }
                add = !add;
            }

            ans[i][j] = ans[j][i] = 2LL * ways % MOD;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << arrange * ans[id(s[x - 1])][id(s[y - 1])] % MOD << '\n';
    }
}
```

---


