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
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 1;

    for (long long x : a) {
        if (x > ans) {
            break;
        }
        ans += x;
    }

    cout << ans << '\n';

    return 0;
}
```

---


