# []

> **原题链接:** (https://codeforces.com/contest/2259/problem/E)

**涉及知识点:** [[构造]], [[差分]]，[[补题]],[[1]],[[]]

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

        vector<int> b(n);
        for (int &x : b) {
            cin >> x;
        }

        // diff 用来标记所有不能放宝藏的区间
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            if (b[i] <= 0) {
                // b[i] == -1：没有约束
                // b[i] == 0：距离小于 0 的位置不存在
                continue;
            }

            int d = b[i];

            // 所有满足 |j - i| < d 的位置都不能放宝藏
            int l = max(0, i - d + 1);
            int r = min(n - 1, i + d - 1);

            if (l <= r) {
                ++diff[l];
                --diff[r + 1];
            }
        }

        vector<bool> banned(n, false);
        int cover = 0;

        for (int i = 0; i < n; ++i) {
            cover += diff[i];
            banned[i] = (cover > 0);
        }

        bool possible = true;

        // 每个已知距离必须至少有一个合法的等距端点
        for (int i = 0; i < n; ++i) {
            if (b[i] == -1) {
                continue;
            }

            int d = b[i];
            bool hasTreasurePosition = false;

            int left = i - d;
            int right = i + d;

            if (left >= 0 && !banned[left]) {
                hasTreasurePosition = true;
            }

            if (right < n && !banned[right]) {
                hasTreasurePosition = true;
            }

            if (!hasTreasurePosition) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << -1 << '\n';
            continue;
        }

        // 极大化构造：所有未被禁止的位置都放宝藏
        string answer(n, '0');

        for (int i = 0; i < n; ++i) {
            if (!banned[i]) {
                answer[i] = '1';
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---


