# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX_N = 10000000;

vector<bool> is_prime;
vector<int> primes;

void init_sieve() {
    is_prime.assign(MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; 1LL * i * i <= MAX_N; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

vector<int> get_prime_factors(int n) {
    vector<int> factors;

    for (int p : primes) {
        if (1LL * p * p > n) break;
        if (n % p != 0) continue;

        factors.push_back(p);
        while (n % p == 0) n /= p;
    }

    if (n > 1) factors.push_back(n);
    return factors;
}

ll count_coprime(ll left, ll right, const vector<int>& factors) {
    if (left > right) return 0;

    ll result = 0;
    int m = factors.size();

    for (int mask = 0; mask < (1 << m); ++mask) {
        ll product = 1;
        int bits = 0;

        for (int i = 0; i < m; ++i) {
            if (mask >> i & 1) {
                product *= factors[i];
                ++bits;
            }
        }

        ll count = right / product - (left - 1) / product;
        if (bits & 1) {
            result -= count;
        } else {
            result += count;
        }
    }

    return result;
}

void solve() {
    int l, r, n;
    cin >> l >> r >> n;

    int p = n;
    while (!is_prime[p]) --p;

    vector<int> factors = get_prime_factors(n);
    ll answer = 0;

    int low_right = min(r, p - 1);
    if (l <= low_right) {
        ll count = low_right - l + 1LL;
        ll coprime = count_coprime(l, low_right, factors);

        // cost(x, n) is 1 when gcd(x, n) = 1, otherwise it is 2.
        answer += 2 * count - coprime;
    }

    // Only the suffix [p, n] needs an exact shortest-path DP.
    int length = n - p + 1;
    vector<int> dp(length, INT_MAX);
    dp[n - p] = 0;

    for (int u = n - 1; u >= p; --u) {
        int best = gcd(u, n);

        for (int v = u + 1; v < n; ++v) {
            best = min(best, gcd(u, v) + dp[v - p]);
        }

        dp[u - p] = best;
    }

    for (int x = max(l, p); x <= r; ++x) {
        answer += dp[x - p];
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_sieve();

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}

```

---


