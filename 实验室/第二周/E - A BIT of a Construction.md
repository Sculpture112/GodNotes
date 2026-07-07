# []

> **原题链接:** ()

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
        long long k;
        cin >> n >> k;

        if (n == 1) {
            cout << k << '\n';
            continue;
        }

        long long x = 1;
        while (x * 2 - 1 <= k) {
            x *= 2;
        }

        long long first = x - 1;
        long long second = k - first;

        cout << first << ' ' << second;
        for (int i = 3; i <= n; i++) {
            cout << ' ' << 0;
        }
        cout << '\n';
    }

    return 0;
}
```

---


