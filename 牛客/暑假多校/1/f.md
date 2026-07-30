# []

> **原题链接:** (https://ac.nowcoder.com/acm/discuss/tutorials?tagId=306866)

**涉及知识点:** [[构造]], [[数学]]，[[补题]],[[]],[[]]

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
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> p(n);
    for (int& v : p) cin >> v;

    int d = (x - p[k] + n) % n;
    for (int i = 0; i < n; ++i) {
        cout << (p[i] + d) % n << " \n"[i + 1 == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
```

---


