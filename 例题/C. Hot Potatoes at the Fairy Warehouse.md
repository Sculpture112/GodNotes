# [[2]]

> **原题链接:** (https://codeforces.com/contest/2256/problem/C)

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

    int T;
    cin >> T;

    while (T--) {
        int n;
        long long k;
        string s;

        cin >> n >> k;
        cin >> s;

        int red = 0, blue = 0;
        int m = 2 * n;

        for (int i = 0; i < m; ++i) {
            if (s[i] == '0') continue;
			// 这里是i和题目对下标正好相反
            int team = i & 1;  // 0: Red, 1: Blue

            if (s[(i + 1) % m] == '0') {
                // 最后一轮传给对方，当前位置所属队伍得分
                if (team == 0) ++red;
                else ++blue;
            } else {
                // 无法传递，土豆留在原队伍，对方得分
                if (team == 0) ++blue;
                else ++red;
            }
        }

        cout << red << ' ' << blue << '\n';
    }

    return 0;
}
```

---


