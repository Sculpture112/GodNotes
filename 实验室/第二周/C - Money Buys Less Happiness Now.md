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

    int T;
    cin >> T;

    while (T--) {
        int n;
        long long x;
        cin >> n >> x;

        priority_queue<int> pq;
        long long sum = 0;

        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;

            pq.push(c);
            sum += c;

            long long available = 1LL * (i - 1) * x;

            if (sum > available) {
                sum -= pq.top();
                pq.pop();
            }
        }

        cout << pq.size() << '\n';
    }

    return 0;
}
```

---


