# []

> **原题链接:** ()

**涉及知识点:** [[数位DP]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long dp[2][2][2][3] = {};
        dp[0][0][0][0] = 1;
        for (int bit = 0; bit < 62; ++bit) {
            long long next[2][2][2][3] = {};
            int nbit = (n >> bit) & 1;
            for (int previousX = 0; previousX < 2; ++previousX) {
                for (int previousR = 0; previousR < 2; ++previousR) {
                    for (int borrow = 0; borrow < 2; ++borrow) {
                        for (int highest = 0; highest < 3; ++highest) {
                            long long ways = dp[previousX][previousR][borrow][highest];
                            if (!ways) continue;
                            for (int x = 0; x < 2; ++x) {
                                if (x && (bit >= 60 || previousX)) continue;
                                for (int r = 0; r <= x; ++r) {
                                    int cbit = x + previousR;
                                    int nextBorrow = nbit < cbit + borrow;
                                    int nextHighest = x ? r + 1 : highest;
                                    long long& target = next[x][r][nextBorrow][nextHighest];
                                    target += ways;
                                    if (target >= MOD) target -= MOD;
                                }
                            }
                        }
                    }
                }
            }
            memcpy(dp, next, sizeof(dp));
        }
        cout << dp[0][0][0][2] << '\n';
    }
    return 0;
}

```



```cpp
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

constexpr int MOD = 1'000'000'007;
constexpr int INV2 = 500'000'004;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ull n;
        cin >> n;

        static int dp[2][2][2][2][2];
        static int ndp[2][2][2][2][2];

        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0][0] = 1;

        for (int bit = 0; bit <= 60; ++bit) {
            memset(ndp, 0, sizeof(ndp));
            int nBit = (n >> bit) & 1ULL;

            for (int carry = 0; carry <= 1; ++carry) {
                for (int prevB = 0; prevB <= 1; ++prevB) {
                    for (int borrowA = 0; borrowA <= 1; ++borrowA) {
                        for (int borrowB = 0; borrowB <= 1; ++borrowB) {
                            for (int borrowC = 0; borrowC <= 1; ++borrowC) {
                                int ways =
                                    dp[carry][prevB][borrowA][borrowB][borrowC];

                                if (ways == 0) continue;

                                for (int aBit = 0; aBit <= 1; ++aBit) {
                                    for (int bBit = 0; bBit <= 1; ++bBit) {
                                        int cBit = aBit ^ bBit;
                                        int sum = aBit + cBit + carry;

                                        if ((sum & 1) != prevB) continue;

                                        int nextCarry = sum >> 1;
                                        int nextBorrowA =
                                            (aBit + borrowA > nBit);
                                        int nextBorrowB =
                                            (bBit + borrowB > nBit);
                                        int nextBorrowC =
                                            (cBit + borrowC > nBit);

                                        int &to = ndp[nextCarry][bBit]
                                                      [nextBorrowA]
                                                      [nextBorrowB]
                                                      [nextBorrowC];

                                        to += ways;
                                        if (to >= MOD) to -= MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            memcpy(dp, ndp, sizeof(dp));
        }

        ll total = dp[0][0][0][0][0];
        total += dp[1][1][0][0][0];
        total %= MOD;

        ll answer = (total - 1 + MOD) % MOD;
        answer = answer * INV2 % MOD;

        cout << answer << '\n';
    }

    return 0;
}
```
---


