# [[0]]

> **原题链接:** (https://codeforces.com/contest/2250/problem/B)

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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int r = n - k;
        if (r == 1) {
            cout << -1 << '\n';
            continue;
        }

        int zeroBlocks = (r + 1) / 2;
        int oneBlocks = r / 2;
        int extraZeros = (n + 1) / 2 - zeroBlocks;
        int extraOnes = n / 2 - oneBlocks;

        string s;
        s.reserve(n);
        for (int i = 0; i < r; ++i) {
            if (i % 2 == 0)
                s.append(1 + (i == 0 ? extraZeros : 0), '0');
            else
                s.append(1 + (i == 1 ? extraOnes : 0), '1');
        }
        cout << s << '\n';
    }
    return 0;
}
```

---


