# [[0]]

> **原题链接:** (https://codeforces.com/gym/715305/problem/K)

**涉及知识点:** [[差分]], [[]]，[[补题]],[[]],[[]]

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

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int64> a(n + 1);
    vector<int64> diffK(n + 3, 0);
    vector<int64> diffB(n + 3, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 在 [l, r] 上加 k * i + b
    auto add = [&](int l, int r, int64 k, int64 b) {
        if (l > r) return;

        diffK[l] += k;
        diffK[r + 1] -= k;

        diffB[l] += b;
        diffB[r + 1] -= b;
    };

    while (m--) {
        int L, R;
        cin >> L >> R;

        int mid = (L + R) / 2;

        // i - L + 1 = 1 * i + (1 - L)
        add(L, mid, 1, 1LL - L);

        // R - i + 1 = -1 * i + (R + 1)
        add(mid + 1, R, -1, 1LL + R);
    }

    int64 k = 0, b = 0;

    for (int i = 1; i <= n; ++i) {
        k += diffK[i];
        b += diffB[i];

        a[i] += k * i + b;

        if (i > 1) cout << ' ';
        cout << a[i];
    }

    cout << '\n';
    return 0;
}
```

---


