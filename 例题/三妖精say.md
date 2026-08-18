# []

> **原题链接:** (https://ac.nowcoder.com/acm/problem/309202)

**涉及知识点:** [[枚举]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll cnt[26] = {};

    for (char c : s) {
        cnt[c - 'a']++;
    }

    ll ans = 0;

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            for (int k = j + 1; k < 26; k++) {
                ll ways = cnt[i] % MOD;
                ways = ways * cnt[j] % MOD;
                ways = ways * cnt[k] % MOD;

                ans = (ans + ways) % MOD;
            }
        }
    }

    // 三个位置上的字符可以任意排列，共 3! = 6 种
    ans = ans * 6 % MOD;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
```

---


