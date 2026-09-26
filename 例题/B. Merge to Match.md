# [[0]]

> **原题链接:** (https://codeforces.com/contest/2248/problem/B)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 
[[2026-09-26-16-18-31]]

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
    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (long long &x : a) cin >> x;
    for (long long &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (n < 2 * m) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < m; ++i) {
        if (b[i] < a[i] || b[i] > a[n - m + i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
```

---


