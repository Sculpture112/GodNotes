# []

> **原题链接:** ()

**涉及知识点:** [[gcd]], [[质因数]]，[[补题]],[[容斥原理]],[[DP]],[[优化枚举]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 题目中 n 最大为 1e7，因此可以直接筛出范围内所有质数。
const int MAX_N = 10000000;

vector<bool> is_prime;
vector<int> primes;

// 埃氏筛：预处理 [1, 1e7] 内的质数。
// 一方面用于寻找不超过 n 的最大质数，
// 另一方面用于分解 n 的不同质因子。
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
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

// 求出 n 的所有不同质因子。
// 例如 n = 12 = 2^2 * 3，返回 {2, 3}。
vector<int> get_prime_factors(int n) {
    vector<int> factors;

    for (int p : primes) {
        if (1LL * p * p > n) break;
        if (n % p != 0) continue;

        factors.push_back(p);

        // 这里只关心不同质因子，因此把因子 p 全部除掉。
        while (n % p == 0) {
            n /= p;
        }
    }

    // 如果最后剩下的数大于 1，它本身就是一个质因子。
    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

// 使用容斥原理，统计区间 [left, right] 中与 n 互质的数的数量。
// factors 是 n 的所有不同质因子。
ll count_coprime(
    ll left,
    ll right,
    const vector<int>& factors
) {
    if (left > right) return 0;

    ll result = 0;
    int m = factors.size();

    // 枚举选取了哪些质因子。
    for (int mask = 0; mask < (1 << m); ++mask) {
        ll product = 1;
        int bits = 0;

        for (int i = 0; i < m; ++i) {
            if (mask >> i & 1) {
                product *= factors[i];
                ++bits;
            }
        }

        // 区间中 product 的倍数个数。
        ll count =
            right / product -
            (left - 1) / product;

        // 容斥原理：
        // 选择偶数个质因子时加，选择奇数个时减。
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

    // 找到不超过 n 的最大质数 p。
    //
    // 在 1e7 范围内，相邻质数之间的距离很小，
    // 因此后面只需要对很短的区间 [p, n] 做 DP。
    int p = n;
    while (!is_prime[p]) {
        --p;
    }

    // 分解 n，用于统计区间中与 n 互质的数。
    vector<int> factors = get_prime_factors(n);

    ll answer = 0;

    /*
     * 处理 x < p 的部分。
     *
     * 因为 p 是质数并且 x < p，所以：
     *     gcd(x, p) = 1。
     *
     * 同时 p 是不超过 n 的最大质数。
     * 若 p < n，根据质数分布可知 p > n / 2，
     * 因此 p 不可能整除 n，从而：
     *     gcd(p, n) = 1。
     *
     * 所以存在路径：
     *     x -> p -> n
     *
     * 总费用为：
     *     gcd(x, p) + gcd(p, n) = 2。
     *
     * 因此 cost(x, n) 最大为 2：
     *
     * 1. gcd(x, n) = 1：
     *    直接走 x -> n，费用为 1。
     *
     * 2. gcd(x, n) > 1：
     *    直接走费用大于 1，而任何至少两条边的路径
     *    费用至少为 2，因此最短路恰好为 2。
     */
    int low_right = min(r, p - 1);

    if (l <= low_right) {
        ll count = low_right - l + 1LL;

        // cost(x, n) = 1 的数，恰好是与 n 互质的 x。
        ll coprime =
            count_coprime(l, low_right, factors);

        // 假设所有数的答案都是 2，贡献为 2 * count。
        // 每个互质的数实际答案为 1，因此减去 coprime。
        answer += 2 * count - coprime;
    }

    /*
     * 精确处理后缀 [p, n]。
     *
     * 定义：
     *     dp[u - p] = cost(u, n)
     *
     * 因为图中的边只能从小编号走向大编号，
     * 所以可以按照 u 从大到小计算。
     *
     * 从 u 到 n 有两种选择：
     *
     * 1. 直接走到 n：
     *        gcd(u, n)
     *
     * 2. 先走到某个 u < v < n，再从 v 走到 n：
     *        gcd(u, v) + dp[v - p]
     */
    int length = n - p + 1;
    vector<int> dp(length, INT_MAX);

    // 从 n 到 n 不需要任何费用。
    dp[n - p] = 0;

    for (int u = n - 1; u >= p; --u) {
        // 不经过中间点，直接从 u 走到 n。
        int best = gcd(u, n);

        // 枚举第一个到达的中间点 v。
        for (int v = u + 1; v < n; ++v) {
            best = min(
                best,
                gcd(u, v) + dp[v - p]
            );
        }

        dp[u - p] = best;
    }

    // 加上询问区间落在 [p, n) 中的部分。
    for (int x = max(l, p); x <= r; ++x) {
        answer += dp[x - p];
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 所有测试用例共用同一份质数表，只需预处理一次。
    init_sieve();

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

```

---


