# []

> **原题链接:** (https://vjudge.net/contest/827785#problem/H)

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

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        cout << "1 1\n";
        cout << -a[1] << "\n";
        cout << "1 1\n";
        cout << 0 << "\n";
        cout << "1 1\n";
        cout << 0 << "\n";
        return 0;
    }

    cout << "1 1\n";
    cout << -a[1] << "\n";

    cout << "2 " << n << "\n";
    for (int i = 2; i <= n; i++) {
        cout << a[i] * (n - 1) << " ";
    }
    cout << "\n";

    cout << "1 " << n << "\n";
    cout << 0 << " ";
    for (int i = 2; i <= n; i++) {
        cout << -a[i] * n << " ";
    }
    cout << "\n";

    return 0;
}
```

---


