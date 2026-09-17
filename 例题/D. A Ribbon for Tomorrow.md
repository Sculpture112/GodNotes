# [[1]]

> **原题链接:** (https://codeforces.com/contest/2256/problem/D)

**涉及知识点:** [[逆元]], [[费马小定理]]，[[补题]],[[]],[[]]

**核心套路:**  [[2026-09-16-20-03-06]]

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

using int64 = long long;

constexpr int MOD = 998244353;
constexpr int MAX_N = 1'000'000;

int64 fac[MAX_N + 1];
int64 ifac[MAX_N + 1];
// [[2026-09-16-19-45-42]]
int64 qpow(int64 a, int64 b) {
    int64 result = 1;

    while (b > 0) {
        if (b & 1) {
            result = result * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }

    return result;
}

int64 C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;

    for (int i = 1; i <= MAX_N; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    ifac[MAX_N] = qpow(fac[MAX_N], MOD - 2);

    for (int i = MAX_N; i >= 1; --i) {
        ifac[i - 1] = ifac[i] * i % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        int cnt[2] = {0, 0};
        int seg[2] = {0, 0};

        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            ++cnt[x];

            if (i == 0 || s[i] != s[i - 1]) {
                ++seg[x];
            }
        }

        int64 answer = 1;

        for (int x = 0; x < 2; ++x) {
            if (cnt[x] > 0) {
                answer = answer * C(cnt[x] - 1, seg[x] - 1) % MOD;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---


