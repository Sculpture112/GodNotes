# []

> **原题链接:** (https://vjudge.net/contest/827785#problem/G)

**涉及知识点:** [[字符串]], [[贪心算法]]，[[补题]],[[]],[[]]

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
        string a, b;
        cin >> n >> a >> b;

        vector<int> ans;

        int l = 0, r = n - 1;
        bool rev = false;

        auto get = [&](int pos) {
            char c = a[pos];
            if (rev) {
                c = (c == '0' ? '1' : '0');
            }
            return c;
        };

        for (int i = n - 1; i >= 0; i--) {
            char first = rev ? get(r) : get(l);
            char last = rev ? get(l) : get(r);

            if (last == b[i]) {
                if (rev) l++;
                else r--;
                continue;
            }

            if (first == b[i]) {
                ans.push_back(1);
            }

            ans.push_back(i + 1);
            rev = !rev;

            if (rev) l++;
            else r--;
        }

        cout << ans.size();
        for (int x : ans) {
            cout << ' ' << x;
        }
        cout << '\n';
    }

    return 0;
}
```

---


