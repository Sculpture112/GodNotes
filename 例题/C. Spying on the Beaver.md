# []

> **原题链接:** (https://codeforces.com/contest/2257/problem/C)

**涉及知识点:** [[构造]], [[]]，[[补题]],[[]],[[]]

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

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        // 父节点信息对该构造没有实际用途，但需要读入
        for (int i = 2, p; i <= n; ++i) {
            cin >> p;
        }

        int m;
        cin >> m;

        vector<int> dams(m);
        bool rootIsDam = false;

        for (int &u : dams) {
            cin >> u;
            if (u == 1) {
                rootIsDam = true;
            }
        }

        int skipped;

        if (rootIsDam) {
            skipped = 1;
        } else {
            skipped = *min_element(dams.begin(), dams.end());
        }

        cout << m - 1;

        for (int u : dams) {
            if (u != skipped) {
                // 输出 u 代表在边 (p[u], u) 上安装摄像头
                cout << ' ' << u;
            }
        }

        cout << '\n';
    }

    return 0;
}
```

---


