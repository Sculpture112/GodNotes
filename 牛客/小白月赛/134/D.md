# []

> **原题链接:** (https://ac.nowcoder.com/acm/contest/137072/D)

**涉及知识点:** [[贪心算法]], [[传送门]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<long long, int>> pos;
    pos.reserve(n + m);

    long long a = LLONG_MAX, b = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        a = min(a, abs(x));
        pos.push_back({x, 0}); // red
    }

    for (int i = 0; i < m; ++i) {
        long long x;
        cin >> x;
        b = min(b, abs(x));
        pos.push_back({x, 1}); // blue
    }

    sort(pos.begin(), pos.end());

    long long c = LLONG_MAX;
    for (int i = 1; i < n + m; ++i) {
        if (pos[i].second != pos[i - 1].second) {
            c = min(c, pos[i].first - pos[i - 1].first);
        }
    }

    cout << min({a + b + c, 2 * (a + c), 2 * (b + c)}) << '\n';
    return 0;
}
```

---


