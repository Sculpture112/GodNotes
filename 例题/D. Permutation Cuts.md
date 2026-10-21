# [[1]]

> **原题链接:** (https://codeforces.com/contest/2250/problem/D)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 
[[2026-10-16-11-16-35]]
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

constexpr int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    bool invalid = false;

    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        if (a[i] == n) invalid = true;
    }

    if (invalid) {
        cout << 0 << '\n';
        return;
    }

    // pre[i]：a[1..i] 是否单调不减
    // suf[i]：a[i..n-1] 是否单调不增
    vector<char> pre(n + 1, false), suf(n + 1, false);

    pre[0] = true;
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] && a[i - 1] <= a[i];
    }

    suf[n] = true;
    for (int i = n - 1; i >= 1; --i) {
        suf[i] = suf[i + 1] && a[i] >= a[i + 1];
    }

    long long answer = 0;
	// [[2026-10-16-14-34-47]]
    for (int c = 0; c < n; ++c) {
        if (!pre[c] || !suf[c + 1]) continue;

        if (c > 0 && c < n - 1 && a[c] == a[c + 1]) {
            continue;
        }

        // 左侧正向读取，右侧反向读取
        int l = 1, r = n - 1;
        int used = 0;  // 已处理的位置数，不包含 n
        int last = 0;  // 上一次处理的最大值要求
        long long ways = 1;

        while (l <= c || r > c) {
            int x;

            if (l > c) {
                x = a[r--];
            } else if (r <= c) {
                x = a[l++];
            } else if (a[l] < a[r]) {
                x = a[l++];
            } else if (a[l] > a[r]) {
                x = a[r--];
            } else {
                // 同一个值同时出现在左右两侧，发生冲突
                ways = 0;
                break;
            }

            if (x == last) {
                // 当前是第 used+1 步，选择数为 x-used
                int choices = x - used;

                if (choices <= 0) {
                    ways = 0;
                    break;
                }

                ways = ways * choices % MOD;
            }
            // x 首次出现时，必须填 x，选择数为 1

            last = x;
            ++used;
        }

        answer = (answer + ways) % MOD;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
```

---


