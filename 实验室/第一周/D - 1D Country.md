# []

> **原题链接:** (https://vjudge.net/contest/826612#problem/D)

**涉及知识点:** [[二分查找]], [[]]，[[补题]],[[]],[[]]

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

    int N;
    cin >> N;

    vector<ll> X(N), P(N);

    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<ll> prefix(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + P[i];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        ll L, R;
        cin >> L >> R;

        int left = lower_bound(X.begin(), X.end(), L) - X.begin();
        int right = upper_bound(X.begin(), X.end(), R) - X.begin();

        cout << prefix[right] - prefix[left] << '\n';
    }

    return 0;
}
```

---


