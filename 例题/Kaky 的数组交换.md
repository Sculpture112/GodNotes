# [[0]]

> **原题链接:** (https://ac.nowcoder.com/acm/contest/139936?channelPut=tracker1)

**涉及知识点:** [[映射]], [[分类讨论]]，[[补题]],[[置换奇偶性不变量]],[[]]

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

        vector<int> a(n), b(n), c(n), d(n);

        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        for (int &x : c) cin >> x;
        for (int &x : d) cin >> x;

        vector<int> mate(2 * n + 1);
        vector<int> isBottom(2 * n + 1, 0);

        for (int i = 0; i < n; ++i) {
            mate[a[i]] = b[i];
            mate[b[i]] = a[i];
            isBottom[b[i]] = 1;
        }

        bool ok = true;
        int flipParity = 0;

        for (int i = 0; i < n; ++i) {
            // 目标中的两个元素必须来自初始状态的同一列
            if (mate[c[i]] != d[i]) {
                ok = false;
            }

            // 若目标上方元素原本位于下方，则这一列被翻转
            flipParity ^= isBottom[c[i]];
        }

        cout << (ok && flipParity == 0 ? "Yes" : "No") << '\n';
    }

    return 0;
}
```

---


