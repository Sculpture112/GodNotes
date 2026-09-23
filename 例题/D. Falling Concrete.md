# [[1]]

> **原题链接:** (https://codeforces.com/contest/2266/problem/D)

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

void solve() {
    int n;
    cin >> n;

    [[maybe_unused]] int ballast = 0;

    vector<long long> b(n);

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        b[i] = a - (i + 1);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int answer = 1;
    int current = 1;

    for (int i = 1; i < static_cast<int>(b.size()); ++i) {
        if (b[i] == b[i - 1] + 1) {
            ++current;
        } else {
            current = 1;
        }

        answer = max(answer, current);
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
```

---


