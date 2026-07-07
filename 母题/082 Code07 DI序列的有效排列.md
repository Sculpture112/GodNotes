# [082 Code07 DI序列的有效排列]

> **原题链接:** (https://leetcode.cn/problems/valid-permutations-for-di-sequence/)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
dfs(i, less) {
    枚举 perm[i] 能选什么;
    累加 dfs(i + 1, newLess);
}
这份代码的状态来自递归思路：
从当前状态出发，问后面还能怎么填。


#include <bits/stdc++.h>
using namespace std;

// DI序列的有效排列
// 给定一个长度为n的字符串s，其中s[i]是:
// "D"意味着减少，"I"意味着增加
// 有效排列是对有n+1个在[0,n]范围内的整数的一个排列perm，使得对所有的i：
// 如果 s[i] == 'D'，那么 perm[i] > perm[i+1]
// 如果 s[i] == 'I'，那么 perm[i] < perm[i+1]
// 返回有效排列的perm的数量
// 因为答案可能很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/valid-permutations-for-di-sequence/
class Solution {
public:
    int numPermsDISequence(string s) {
        const int mod = 1000000007;
        int n = s.size() + 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        //这里dp的定义很特别，是从i位置，less个数字开始选，后续有多少个方案，注意是后续而不是前面的方案数
        for (int less = 0; less <= n; less++) {
            dp[n][less] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == 0 || s[i - 1] == 'D') {
                dp[i][1] = dp[i + 1][0];
                
                //dp[i][3] = dp[i+1][0] + dp[i+1][1] + dp[i+1][2]
                //dp[i][4] = dp[i+1][0] + dp[i+1][1] + dp[i+1][2] + dp[i+1][3]
                //dp[i][4] 比 dp[i][3] 只多了一项
                for (int less = 2; less <= n; less++) {
                    dp[i][less] = (dp[i][less - 1] + dp[i + 1][less - 1]) % mod;
                }
            } else {
                dp[i][n - i - 1] = dp[i + 1][n - i - 1];
                for (int less = n - i - 2; less >= 0; less--) {
                    dp[i][less] = (dp[i][less + 1] + dp[i + 1][less]) % mod;
                }
            }
        }
        return dp[0][n];
    }
};
```

---

