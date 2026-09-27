# [[0]]

> **原题链接:** (http://codeforces.com/contest/2247/problem/B)

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

    int t;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;

        if (k > m) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << (i % k == 0 ? m - k + 1 : 1);
            cout << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
```

---


