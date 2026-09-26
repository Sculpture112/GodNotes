# [[0]]

> **原题链接:** (https://codeforces.com/contest/2248/problem/D)

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

void solve() {
    int n, q;
    cin >> n >> q;

    string s, t;
    cin >> s >> t;

    // pref[i][type]：前 i 个位置中，type 类型出现的次数
    // type:
    // 0 -> (0, 0)
    // 1 -> (0, 1)
    // 2 -> (1, 0)
    // 3 -> (1, 1)
    vector<array<int, 4>> pref(n + 1);

    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];

        int a = s[i - 1] - '0';
        int b = t[i - 1] - '0';
        int type = a * 2 + b;

        ++pref[i][type];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int u = pref[r][0] - pref[l - 1][0]; // (0, 0)
        int x = pref[r][1] - pref[l - 1][1]; // (0, 1)
        int y = pref[r][2] - pref[l - 1][2]; // (1, 0)
        int v = pref[r][3] - pref[l - 1][3]; // (1, 1)

        cout << (abs(x - y) <= u + v ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
```

---


