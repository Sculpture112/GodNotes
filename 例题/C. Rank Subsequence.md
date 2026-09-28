# [[1]]

> **原题链接:** (https://codeforces.com/contest/2250/problem/C)

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

struct Element {
    int l, r, u, v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Element> a(n);
        for (auto &e : a) {
            cin >> e.l >> e.r >> e.u >> e.v;
        }

        int answer = 0;

        for (int m = n; m >= 1; --m) {
            int j = 1;

            for (const auto &e : a) {
                if (j > m) break;

                int rightRank = m - j + 1;
                bool leftValid = (j < e.l || j > e.r);
                bool rightValid = (rightRank < e.u || rightRank > e.v);

                if (leftValid && rightValid) {
                    ++j;
                }
            }

            if (j == m + 1) {
                answer = m;
                break;
            }
        }

        cout << answer << '\n';
    }
}
```

---


