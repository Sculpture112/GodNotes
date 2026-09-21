# [[0]]

> **原题链接:** (https://codeforces.com/contest/2258/problem/C)

**涉及知识点:** [[树的直径]], [[]]，[[补题]],[[]],[[]]

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

bool ask(int u, int v, int d) {
    cout << "? " << u << ' ' << v << ' ' << d << endl;

    int response;
    cin >> response;

    if (response == -1) {
        exit(0);
    }

    return response == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int endpoint = 1;
        int diameter = 0;

        // 第一遍：寻找距离 1 最远的点
        for (int v = 2; v <= n; ++v) {
            while (diameter + 1 <= n &&
                   ask(1, v, diameter + 1)) {
                endpoint = v;
                ++diameter;
            }
        }

        int other = 1;

        // 第二遍：从 endpoint 出发寻找真正的直径
        for (int v = 1; v <= n; ++v) {
            if (v == endpoint) continue;

            while (diameter + 1 <= n &&
                   ask(endpoint, v, diameter + 1)) {
                other = v;
                ++diameter;
            }
        }

        cout << "! " << endpoint << ' '
             << other << ' ' << diameter << endl;
    }

    return 0;
}
```

---


