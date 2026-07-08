# []

> **原题链接:** ()

**涉及知识点:** [[mex]], [[]]，[[补题]],[[]],[[]]

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
    vector<int> inA(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        inA[a[i]] = 1;
    }

    set<int> canUse;

    for (int x = 0; x <= n; x++) {
        if (!inA[x]) {
            canUse.insert(x);
        }
    }

    int last = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > last) {
            b[i] = last;
            canUse.erase(last);
            last = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            if (canUse.empty()) {
                cout << -1 << '\n';
                return 0;
            }

            b[i] = *canUse.begin();
            canUse.erase(canUse.begin());
        }
    }

    set<int> seen;
    int mex = 0;

    for (int i = 0; i < n; i++) {
        seen.insert(b[i]);

        while (seen.count(mex)) {
            mex++;
        }

        if (mex != a[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
    }

    return 0;
}
```

---


