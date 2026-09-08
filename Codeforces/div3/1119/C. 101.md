# []

> **原题链接:** (https://codeforces.com/contest/2259/problem/C)

**涉及知识点:** [[构造]], [[0]]，[[补题]],[[]],[[]]

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

        vector<int> a(n), ones, neg;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) ones.push_back(i);
            if (a[i] == -1) neg.push_back(i);
        }

        int bestL = -1, bestR = -1, bestLen = 0;

        auto update = [&](int l, int r) {
            if (l < 0 || r < 0 || l > r) return;
            if (r - l + 1 > bestLen) {
                bestLen = r - l + 1;
                bestL = l;
                bestR = r;
            }
        };

        if (!ones.empty()) {
            // 相邻固定 1 之间
            for (int i = 0; i + 1 < (int)ones.size(); i++) {
                update(ones[i], ones[i + 1]);
            }

            // 第一 个固定 1 左侧最远的 -1
            for (int i : neg) {
                if (i < ones.front()) {
                    update(i, ones.front());
                    break;
                }
            }

            // 最后一个固定 1 右侧最远的 -1
            for (int i = (int)neg.size() - 1; i >= 0; i--) {
                if (neg[i] > ones.back()) {
                    update(ones.back(), neg[i]);
                    break;
                }
            }

            // 至少保证有一个 1
            if (bestLen == 0) {
                bestL = bestR = ones[0];
                bestLen = 1;
            }
        } else {
            // 没有固定 1，直接让最左和最右的 -1 变成 1
            if ((int)neg.size() >= 2) {
                update(neg.front(), neg.back());
            } else if ((int)neg.size() == 1) {
                bestL = bestR = neg[0];
            }
        }

        // 其余 -1 全部变成 0
        for (int &x : a) {
            if (x == -1) x = 0;
        }

        if (bestL != -1) {
            a[bestL] = 1;
            a[bestR] = 1;
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
```

---


