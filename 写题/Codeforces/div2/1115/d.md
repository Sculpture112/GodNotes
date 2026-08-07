# []

> **原题链接:** ()

**涉及知识点:** [[差分]], [[构造]]，[[补题]],[[贪心算法]],[[]]
https://codeforces.com/contest/1110/problem/E 相似题目
**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n), diff(n - 1);
        for (ll &x : a) cin >> x;

        for (int i = 0; i + 1 < n; ++i) {
            diff[i] = a[i + 1] - a[i];
        }

        int left = 0;
        while (left < n - 1) {
            int right = left + 1;

            while (right < n - 1 &&
                   (diff[right] % 2 != 0) == (diff[left] % 2 != 0)) {
                ++right;
            }

            sort(diff.begin() + left, diff.begin() + right);
            left = right;
        }

        ll current = a[0];
        cout << current;

        for (ll d : diff) {
            current += d;
            cout << ' ' << current;
        }
        cout << '\n';
    }

    return 0;
}
```

---


