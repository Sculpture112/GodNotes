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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> seg(N);
    for (int i = 0; i < N; i++) {
        cin >> seg[i].first >> seg[i].second; // L, R
    }

    sort(seg.begin(), seg.end(), [](auto a, auto b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    auto check = [&](ll x) {
        int cnt = 0;
        ll lastR = -(1LL << 60);

        for (auto [L, R] : seg) {
            if (cnt == 0 || L >= lastR + x) {
                cnt++;
                lastR = R;

                if (cnt >= K) return true;
            }
        }

        return false;
    };

    if (!check(1)) {
        cout << -1 << '\n';
        return 0;
    }

    ll low = 1;
    ll high = 1000000001LL;

    while (high - low > 1) {
        ll mid = (low + high) / 2;

        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << low << '\n';

    return 0;
}
```

---


