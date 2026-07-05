# []

> **原题链接:** (https://atcoder.jp/contests/abc463/tasks/abc463_d?lang=en)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Seg {
    ll l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<Seg> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a.begin(), a.end(), [](const Seg& x, const Seg& y) {
        if (x.r != y.r) return x.r < y.r;
        return x.l < y.l;
    });

    auto check = [&](ll dist) {
        int cnt = 0;
        ll lastR = -(1LL << 60);

        for (auto &s : a) {
            if (s.l - lastR >= dist) {
                cnt++;
                lastR = s.r;
                if (cnt >= K) return true;
            }
        }

        return false;
    };

    if (!check(1)) {
        cout << -1 << '\n';
        return 0;
    }

    ll lo = 1, hi = 1'000'000'000LL, ans = 1;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;

        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---


