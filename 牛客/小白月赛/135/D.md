# []

> **原题链接:** (https://ac.nowcoder.com/acm/contest/137502/D)

**涉及知识点:** [[栈]], [[字符串]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> st;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            int r = x % 9;

            if (!st.empty() && (st.back() + r) % 9 == 0) {
                st.pop_back();
                cnt++;
            } else {
                st.push_back(r);
            }
        }

        if (cnt % 2 == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
```

---


