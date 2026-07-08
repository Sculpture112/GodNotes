# []

> **原题链接:** (https://ac.nowcoder.com/acm/contest/137502/C)

**涉及知识点:** [[贪心算法]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



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
        bool hasZero = false;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) hasZero = true;
        }

        if (hasZero) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = LLONG_MAX;
        vector<long long> cost3;

        for (int i = 0; i < n; i++) {
            long long x = a[i];

            long long c3 = (3 - x % 3) % 3;
            long long c9 = (9 - x % 9) % 9;

            cost3.push_back(c3);
            ans = min(ans, c9);
        }

        sort(cost3.begin(), cost3.end());

        if (n >= 2) {
            ans = min(ans, cost3[0] + cost3[1]);
        }

        cout << ans << "\n";
    }

    return 0;
}

```

---


