# [[0]]

> **原题链接:** (https://codeforces.com/contest/2260/problem/C)

**涉及知识点:** [[异或]], [[]]，[[补题]],[[]],[[]]

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

    int qrTNum;
    cin >> qrTNum;

    while (qrTNum--) {
        long long x, y;
        cin >> x >> y;

        long long sum = x + y;
        long long bestX = 0;
        bool smaller = false;

        for (int bit = 30; bit >= 0; --bit) {
            long long mask = 1LL << bit;

            if (smaller) {
                if (sum & mask) bestX |= mask;
            } else if (x & mask) {
                if (sum & mask) {
                    bestX |= mask;
                } else {
                    smaller = true;
                }
            }
        }

        cout << sum << ' ' << x - bestX << '\n';
    }

    return 0;
}
```

---


