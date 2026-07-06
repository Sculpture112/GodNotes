# []

> **原题链接:** (https://atcoder.jp/contests/abc461/tasks/abc461_f?lang=en)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long x = N;
    vector<pair<long long, int>> primes;

    for (long long p = 2; p * p <= x; p += (p == 2 ? 1 : 2)) {
        if (x % p == 0) {
            int e = 0;
            while (x % p == 0) {
                x /= p;
                e++;
            }
            primes.push_back({p, e});
        }
    }
    if (x > 1) primes.push_back({x, 1});

    vector<long long> divisors = {1};
    for (auto [p, e] : primes) {
        int sz = divisors.size();
        long long mul = 1;
        for (int i = 1; i <= e; i++) {
            mul *= p;
            for (int j = 0; j < sz; j++) {
                divisors.push_back(divisors[j] * mul);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    int D = divisors.size();
    unordered_map<long long, int> id;
    id.reserve(D * 2);

    for (int i = 0; i < D; i++) {
        id[divisors[i]] = i;
    }

    int maxK = 0;
    __int128 prod = 1;
    for (long long v = 2; ; v++) {
        if (prod * v > N) break;
        prod *= v;
        maxK++;
    }

    vector<long long> fact(maxK + 2, 1);
    for (int i = 1; i < (int)fact.size(); i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    vector<vector<long long>> cnt(D, vector<long long>(maxK + 1, 0));
    vector<vector<long long>> sum(D, vector<long long>(maxK + 1, 0));

    cnt[id[1]][0] = 1;

    for (long long d : divisors) {
        if (d == 1) continue;

        long long dMod = d % MOD;

        for (int i = D - 1; i >= 0; i--) {
            __int128 nd128 = (__int128)divisors[i] * d;
            if (nd128 > N) continue;

            long long nd = (long long)nd128;
            if (N % nd != 0) continue;

            int j = id[nd];

            for (int k = maxK - 1; k >= 0; k--) {
                if (cnt[i][k] == 0 && sum[i][k] == 0) continue;

                long long addCnt = cnt[i][k];
                long long addSum = (sum[i][k] + addCnt * dMod) % MOD;

                cnt[j][k + 1] += addCnt;
                cnt[j][k + 1] %= MOD;

                sum[j][k + 1] += addSum;
                sum[j][k + 1] %= MOD;
            }
        }
    }

    int target = id[N];
    long long ans = 0;

    for (int m = 0; m <= maxK; m++) {
        long long c = cnt[target][m];
        long long s = sum[target][m];

        if (m > 0) {
            ans += fact[m] * s % MOD;
            ans %= MOD;
        }

        ans += fact[m + 1] * ((s + c) % MOD) % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
    return 0;
}
```

---


