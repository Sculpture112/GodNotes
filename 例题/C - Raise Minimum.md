# []

> **原题链接:** (https://vjudge.net/contest/826612#problem/C)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;
using ll = long long;

bool ok(const vector<ll>& a, ll K, i128 x) {
    i128 need = 0;
    int n = a.size();

    for (int idx = 0; idx < n; idx++) {
        int i = idx + 1;

        if ((i128)a[idx] < x) {
            i128 diff = x - a[idx];
            need += (diff + i - 1) / i;

            if (need > K) return false;
        }
    }

    return need <= K;
}

void print_i128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    string s;
    while (x > 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }

    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<ll> A(N);
    ll mn = LLONG_MAX;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mn = min(mn, A[i]);
    }

    i128 left = mn;
    i128 right = (i128)mn + (i128)N * K + 1; // 右边界不可行/开区间

    while (right - left > 1) {
        i128 mid = (left + right) / 2;

        if (ok(A, K, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    print_i128(left);
    cout << '\n';

    return 0;
}
```

---


