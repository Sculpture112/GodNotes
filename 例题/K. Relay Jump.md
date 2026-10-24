# [[0]]

> **原题链接:** (https://codeforces.com/gym/106252/problem/K)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

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

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<ll> qx(n + 1), qy(n + 1);
    ll dx = 0, dy = 0;
    ll sx = 0, sy = 0;

    for (int i = 1; i <= n; ++i) {
        ll px, py;
        cin >> px >> py >> qx[i] >> qy[i];

        dx += qx[i] - px;
        dy += qy[i] - py;

        if (i == s) {
            sx = px;
            sy = py;
        }
    }

    // targetX、targetY 是最后被刺激青蛙最终坐标的两倍。
    ll targetX = dx + 2 * sx;
    ll targetY = dy + 2 * sy;

    for (int i = 1; i <= n; ++i) {
        if (2 * qx[i] == targetX &&
            2 * qy[i] == targetY) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
```

---


