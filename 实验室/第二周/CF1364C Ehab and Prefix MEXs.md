# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

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

    vector<int> a(n), b(n, -1);
    vector<int> appeared(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        appeared[a[i]] = 1;
    }

    set<int> unused;

    for (int x = 0; x <= n; x++) {
        if (!appeared[x]) {
            unused.insert(x);
        }
    }

    int last = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > last) {
            b[i] = last;
            last = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            b[i] = *unused.begin();
            unused.erase(unused.begin());
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
    }

    return 0;
}
```

---


