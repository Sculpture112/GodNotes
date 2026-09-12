# [[0]]

> **原题链接:** ()

**涉及知识点:** [[构造]], [[分类讨论]]，[[补题]],[[mex]],[[]]

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
        int n;
        cin >> n;

        vector<long long> a(n);
        int zeroCount = 0;

        for (long long &x : a) {
            cin >> x;
            if (x == 0) {
                ++zeroCount;
            }
        }

        // 恰好只有一个 0，一定无解
        if (zeroCount == 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        // 默认把所有元素放进 A
        string answer(n, 'A');

        if (zeroCount >= 2) {
            bool firstZero = true;

            for (int i = 0; i < n; ++i) {
                if (a[i] != 0) {
                    answer[i] = 'A';
                } else if (firstZero) {
                    // 第一个 0 放进 B
                    answer[i] = 'B';
                    firstZero = false;
                } else {
                    // 剩余的 0 放进 C
                    answer[i] = 'C';
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---


