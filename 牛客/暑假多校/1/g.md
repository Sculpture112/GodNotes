# []

> **原题链接:** ()

**涉及知识点:** [[数学]], [[构造]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;

    const double STEP = 0.011;

    cout << 2 * n << '\n';
    cout << fixed << setprecision(10);

    for (int layer = 0; layer < 2; layer++) {
        for (int i = 0; i < n; i++) {
            int row = i / 10;
            int col = i % 10;

            cout << row * STEP << ' '
                 << col * STEP << ' '
                 << layer << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
```

---


