# []

> **原题链接:** (https://codeforces.com/contest/2238)

**涉及知识点:** [[gcd]], [[lcm]]，[[补题]],[[]],[[]]

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
        long long n;
        cin >> n;

        long long ans = 0;
        for (long long b = 1; b <= n; b++) {
            long long cnt = n / b;
            ans += cnt * cnt;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---


