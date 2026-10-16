# [[0]]

> **原题链接:** (https://codeforces.com/contest/2240/problem/A)

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
        long long n, k;
        cin >> n >> k;

        long long ans = 0;

        for (long long w = 1; w <= n; w *= 2) {
            // 当前位最多有 k 个 1，每个需要花费 w
            long long cnt = min(k, n / w);
            ans += cnt;
            n -= cnt * w;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---


