# []

> **原题链接:** ()

**涉及知识点:** [[贪心算法]], [[分类讨论]]，[[补题]],[[构造]],[[逆向]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TestsNumT;
    cin >> TestsNumT;

    while (TestsNumT--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        int limit = n + m;
        vector<int> state(limit + 1);

        for (int i = 0, v; i < x; ++i) {
            cin >> v;
            state[v] |= 1;
        }

        for (int i = 0, v; i < y; ++i) {
            cin >> v;
            state[v] |= 2;
        }

        int onlyA = 0;
        int onlyB = 0;
        int chosen = 0;
        long long answer = 0;

        for (int v = limit; v >= 1 && chosen < limit - 1; --v) {
            if (state[v] == 1 && onlyA < n) {
                ++onlyA;
                ++chosen;
                answer += v;
            } else if (state[v] == 2 && onlyB < m) {
                ++onlyB;
                ++chosen;
                answer += v;
            } else if (state[v] == 3) {
                ++chosen;
                answer += v;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---


