# [[0]]

> **原题链接:** (https://codeforces.com/contest/2240/problem/B)

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

using int64 = long long;
constexpr int64 MOD = 998244353;

int64 qpow(int64 a, int64 b) {
    int64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int64 n, m, r, c;
        cin >> n >> m >> r >> c;

        int64 freeCells = n * m - (n - r + 1) * (m - c + 1);
        cout << qpow(2, freeCells) << '\n';
    }

    return 0;
}
```

---


