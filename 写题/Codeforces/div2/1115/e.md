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

---


