# [[0]]

> **原题链接:** (https://codeforces.com/contest/2246/problem/C)

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

using ll = long long;
const ll MOD = 1e9 + 7;

ll qpow(ll a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    int d = 0, cnt = 0;
    int pre = -2;
    bool hasNeg = false;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == -1) hasNeg = true;

        if (x != pre) {
            d++;
            if (pre > 0 && x == pre + 1) {
                cnt++;
            }
        }

        pre = x;
    }

    ll ans = qpow(2, n - d);
    if (hasNeg) ans = ans * (cnt + 1) % MOD;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

```

---


