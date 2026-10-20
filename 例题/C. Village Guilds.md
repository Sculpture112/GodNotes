# [[0]]

> **原题链接:** (https://codeforces.com/contest/2238/problem/C)

**涉及知识点:** [[树上dp]], [[分类讨论]]，[[补题]],[[贡献法]],[[]]

[[2026-10-20-19-45-19]]

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
        int n;
        cin >> n;

        vector<int> parent(n + 1);
        for (int i = 2; i <= n; ++i) {
            cin >> parent[i];
        }

        vector<int> first(n + 1, 0);
        vector<int> second(n + 1, 0);

        long long ans = 0;

        for (int v = n; v >= 1; --v) {
            ans += second[v] + 1LL;

            if (v == 1) continue;

            int p = parent[v];
            int h = first[v] + 1;

            if (h >= first[p]) {
                second[p] = first[p];
                first[p] = h;
            } else if (h > second[p]) {
                second[p] = h;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---


