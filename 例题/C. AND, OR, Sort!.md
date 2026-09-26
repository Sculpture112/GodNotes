# [[2]]

> **原题链接:** (https://codeforces.com/contest/2266/problem/C)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 
[[2026-09-23-15-40-50]]
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

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // s[0] 无法改变。
    // 如果第一位是 1，排序后只能是全 1。
    if (s[0] == '1') {
        cout << count(s.begin(), s.end(), '0') << '\n';
        return;
    }

    int onesLeft = 0;
    int zerosRight = count(s.begin(), s.end(), '0');
    int ans = n;

    // 枚举最终 0 和 1 的分界线。
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            --zerosRight;
        } else {
            ++onesLeft;
        }

        ans = min(ans, onesLeft + zerosRight);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
```

---


