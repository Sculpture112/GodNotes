# []

> **原题链接:** ()

**涉及知识点:** [[gcd]], [[模型]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]
cnt[d] 是用来算“所有元素都能被 d 整除的子序列总数”；
dp[d] 是从这个总数里减掉 gcd 更大的倍数后，剩下的“gcd 恰好为 d”的数量。
//这里的dp就是代码中的f


```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int M = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> freq(M + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<long long> pow2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    vector<int> cnt(M + 1, 0);
    for (int d = 1; d <= M; d++) {
        for (int j = d; j <= M; j += d) {
            cnt[d] += freq[j];
        }
    }

    vector<long long> f(M + 1, 0);

    for (int d = M; d >= 1; d--) {
        f[d] = (pow2[cnt[d]] - 1 + MOD) % MOD;

        for (int j = 2 * d; j <= M; j += d) {
            f[d] = (f[d] - f[j] + MOD) % MOD;
        }
    }

    cout << f[1] << '\n';
    return 0;
}
```

---


