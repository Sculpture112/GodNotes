# [[0]]

> **原题链接:** (https://codeforces.com/problemset/problem/1111/D)

**涉及知识点:** [[费马小定理]], [[01背包]]，[[补题]],[[组合数]],[[逆元]]，[[快速幂]]，[[退背包]]

**核心套路:** 
[[2026-09-26-13-21-00]]
[[2026-09-26-14-10-41]]
## 破题切入点 (思维闪念)
[]

阶乘逆元的推导[[2026-09-26-13-51-40]]

**触发条件：**

**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

constexpr int ALPHABET = 52;
constexpr int64 MOD = 1'000'000'007LL;

// 小写字母映射到 0~25
// 大写字母映射到 26~51
int getId(char ch) {
    if ('a' <= ch && ch <= 'z') {
        return ch - 'a';
    }

    return ch - 'A' + 26;
}

int64 modPow(int64 base, int64 exponent) {
    int64 result = 1;

    while (exponent > 0) {
        if (exponent & 1LL) {
            result = result * base % MOD;
        }

        base = base * base % MOD;
        exponent >>= 1LL;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = static_cast<int>(s.size());
    const int h = n / 2;

    /*
     * cnt[c]：字符 c 的出现次数。
     */
    array<int, ALPHABET> cnt{};

    for (char ch : s) {
        ++cnt[getId(ch)];
    }

    /*
     * 预处理阶乘和逆阶乘。
     */
    vector<int64> fact(n + 1);
    vector<int64> invFact(n + 1);

    fact[0] = 1;

    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[n] = modPow(fact[n], MOD - 2);

    for (int i = n; i >= 1; --i) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }

    /*
     * 固定一种分半方法后，左右两半内部的排列数：
     *
     * F = h! * h! / product(cnt[c]!)
     */
    int64 arrangementsPerSplit =
        fact[h] * fact[h] % MOD;

    for (int c = 0; c < ALPHABET; ++c) {
        arrangementsPerSplit =
            arrangementsPerSplit * invFact[cnt[c]] % MOD;
    }

    /*
     * dp[k]：
     * 选择若干种完整字符组，恰好占 k 个位置的方案数。
     */
    vector<int64> dp(h + 1);

    dp[0] = 1;

    for (int c = 0; c < ALPHABET; ++c) {
        const int frequency = cnt[c];

        if (frequency == 0) {
            continue;
        }

        // 01 背包必须倒序
        for (int k = h; k >= frequency; --k) {
            dp[k] += dp[k - frequency];

            if (dp[k] >= MOD) {
                dp[k] -= MOD;
            }
        }
    }

    /*
     * ways[a][b]：
     * 查询字符 a、b 时，符合要求的分半方法数。
     *
     * 暂时不包含内部排列系数 arrangementsPerSplit。
     */
    array<array<int64, ALPHABET>, ALPHABET> ways{};

    /*
     * 相同字符的查询没有增加额外限制。
     */
    for (int a = 0; a < ALPHABET; ++a) {
        ways[a][a] = dp[h];
    }

    /*
     * temp 是工作数组。
     *
     * 每轮外层开始时 temp == dp。
     * 删除 a 后，内层依次删除、恢复每个 b。
     * 内层结束后再恢复 a，使 temp 重新等于 dp。
     */
    vector<int64> temp = dp;

    /*
     * 从当前背包中删除一个大小为 frequency 的字符组。
     *
     * 正序更新：
     * R[k] = D[k] - R[k-frequency]
     */
    auto removeCharacter = [&](int frequency) {
        for (int k = frequency; k <= h; ++k) {
            temp[k] -= temp[k - frequency];

            if (temp[k] < 0) {
                temp[k] += MOD;
            }
        }
    };

    /*
     * 把一个大小为 frequency 的字符组恢复进背包。
     *
     * 相当于重新加入一件 01 背包物品，所以倒序更新。
     */
    auto restoreCharacter = [&](int frequency) {
        for (int k = h; k >= frequency; --k) {
            temp[k] += temp[k - frequency];

            if (temp[k] >= MOD) {
                temp[k] -= MOD;
            }
        }
    };

    /*
     * 预处理所有不同字符对。
     */
    for (int a = 0; a < ALPHABET; ++a) {
        if (cnt[a] == 0) {
            continue;
        }

        /*
         * 整个内层循环期间一直保持 a 被删除。
         */
        removeCharacter(cnt[a]);

        for (int b = a + 1; b < ALPHABET; ++b) {
            if (cnt[b] == 0) {
                continue;
            }

            /*
             * 临时删除 b。
             *
             * 此时 temp[h] 表示：
             * 前半段不选择 a、b，只使用其他字符填满 h 个位置。
             *
             * 因此 a、b 都在后半段。
             */
            removeCharacter(cnt[b]);

            /*
             * 乘以 2：
             * 1. a、b 都在后半段；
             * 2. 交换左右后，a、b 都在前半段。
             */
            ways[a][b] =
                ways[b][a] =
                    2LL * temp[h] % MOD;

            /*
             * 恢复 b，回到只删除 a 的状态，
             * 准备处理下一个字符对。
             */
            restoreCharacter(cnt[b]);
        }

        /*
         * 当前 a 的所有字符对处理完毕。
         * 恢复 a，使 temp 回到原始 dp。
         */
        restoreCharacter(cnt[a]);
    }

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;

        const int a = getId(s[x - 1]);
        const int b = getId(s[y - 1]);

        const int64 answer =
            ways[a][b] * arrangementsPerSplit % MOD;

        cout << answer << '\n';
    }

    return 0;
}
```

---

```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

int id(char ch) {
    if ('a' <= ch && ch <= 'z') return ch - 'a';
    return ch - 'A' + 26;
}

int modpow(int a, int e) {
    long long res = 1, base = a;
    while (e) {
        if (e & 1) res = res * base % MOD;
        base = base * base % MOD;
        e >>= 1;
    }
    return (int)res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size(), half = n / 2;

    array<int, 52> cnt{};
    for (char ch : s) ++cnt[id(ch)];

    vector<int> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;

    invfac[n] = modpow(fac[n], MOD - 2);
    for (int i = n; i >= 1; --i)
        invfac[i - 1] = 1LL * invfac[i] * i % MOD;

    long long arrange = 1LL * fac[half] * fac[half] % MOD;
    for (int c : cnt)
        arrange = arrange * invfac[c] % MOD;

    vector<int> dp(half + 1);
    dp[0] = 1;
    for (int c : cnt) {
        if (c == 0 || c > half) continue;
        for (int k = half; k >= c; --k) {
            dp[k] += dp[k - c];
            if (dp[k] >= MOD) dp[k] -= MOD;
        }
    }

    int ans[52][52]{};
    for (int i = 0; i < 52; ++i)
        ans[i][i] = dp[half];

    for (int i = 0; i < 52; ++i) {
        if (cnt[i] == 0) continue;

        vector<int> without_i = dp;
        for (int k = cnt[i]; k <= half; ++k) {
            without_i[k] -= without_i[k - cnt[i]];
            if (without_i[k] < 0) without_i[k] += MOD;
        }

        for (int j = i + 1; j < 52; ++j) {
            if (cnt[j] == 0 || cnt[i] + cnt[j] > half) continue;

            int ways = 0;
            bool add = true;
            for (int k = half; k >= 0; k -= cnt[j]) {
                if (add) {
                    ways += without_i[k];
                    if (ways >= MOD) ways -= MOD;
                } else {
                    ways -= without_i[k];
                    if (ways < 0) ways += MOD;
                }
                add = !add;
            }

            ans[i][j] = ans[j][i] = 2LL * ways % MOD;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << arrange * ans[id(s[x - 1])][id(s[y - 1])] % MOD << '\n';
    }
}
```
