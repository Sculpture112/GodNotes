# [[0]]

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]
[[]]
**核心套路:** 

- 题目中的什么条件提示了这个方向？
- 从最直接的做法出发，怎样走到关键观察？
- 如果没见过这题，我能靠什么发现它？


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

        vector<int> h(n), clockwise(n);
        for (int &x : h) cin >> x;

        // 枚举空容器
        for (int l = 0; l < n; ++l) {
            int mx = 0;

            // 顺时针：走到 i 时，新经过的是 h[i - 1]
            for (int step = 1; step < n; ++step) {
                int i = (l + step) % n;
                int edge = (i - 1 + n) % n;

                mx = max(mx, h[edge]);
                clockwise[i] = mx;
            }

            long long ans = 0;
            mx = 0;

            // 逆时针：走到 i 时，新经过的是 h[i]
            for (int step = 1; step < n; ++step) {
                int i = (l - step + n) % n;

                mx = max(mx, h[i]);
                ans += min(clockwise[i], mx);
            }

            cout << ans << (l + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
```

---


