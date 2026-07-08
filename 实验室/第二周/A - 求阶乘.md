# []

> **原题链接:** (https://vjudge.net/contest/827785#problem/A)

**涉及知识点:** [[二分答案法]], [[模型]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int64 zeroCount(int64 n) {
    int64 res = 0;
    while (n) {
        n /= 5;
        res += n;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 K;
    cin >> K;

    int64 l = 1, r = 5 * K + 5;

    while (l < r) {
        int64 mid = l + (r - l) / 2;
        if (zeroCount(mid) >= K) r = mid;
        else l = mid + 1;
    }

    if (zeroCount(l) == K) cout << l << '\n';
    else cout << -1 << '\n';

    return 0;
}
```

---


