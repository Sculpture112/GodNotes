# []

> **原题链接:** (https://leetcode.cn/problems/decode-ways-ii/
)

**涉及知识点:** [[已AC]], [[一维DP]]，[[需重刷]],[[分类讨论]],[[]]

**难度 [[]]


```cpp
// 066 Code04 解码方法 II

// 一条包含字母 A-Z 的消息通过以下的方式进行了 编码 ：
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// 要 解码 一条已编码的消息，所有的数字都必须分组
// 然后按原来的编码方案反向映射回字母（可能存在多种方式）
// 例如，"11106" 可以映射为："AAJF"、"KJF"
// 注意，像 (1 11 06) 这样的分组是无效的，"06"不可以映射为'F'
// 除了上面描述的数字字母映射方案，编码消息中可能包含 '*' 字符
// 可以表示从 '1' 到 '9' 的任一数字（不包括 '0'）
// 例如，"1*" 可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19"
// 对 "1*" 进行解码，相当于解码该字符串可以表示的任何编码消息
// 给你一个字符串 s ，由数字和 '*' 字符组成，返回 解码 该字符串的方法 数目
// 由于答案数目可能非常大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/decode-ways-ii/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    const long long MOD = 1000000007;

    int numDecodings(string s) {
        // 四种方法任选其一均可
        // return numDecodings1(s);
        // return numDecodings2(s);
        // return numDecodings3(s);
        return numDecodings4(s);
    }

    // 没有取模逻辑
    // 最自然的暴力尝试
    int numDecodings1(const string& s) {
        return f1(s, 0);
    }

    // s[i....] 有多少种有效转化
    int f1(const string& s, int i) {
        int n = s.length();
        if (i == n) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        // s[i] != '0'
        // 2) i想单独转
        int ans = f1(s, i + 1) * (s[i] == '*' ? 9 : 1);
        // 3) i i+1 一起转化 <= 26
        if (i + 1 < n) {
            // 有i+1位置
            if (s[i] != '*') {
                if (s[i + 1] != '*') {
                    // num num
                    //  i  i+1
                    if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                        ans += f1(s, i + 2);
                    }
                } else {
                    // num  *
                    //  i  i+1
                    if (s[i] == '1') {
                        ans += f1(s, i + 2) * 9;
                    }
                    if (s[i] == '2') {
                        ans += f1(s, i + 2) * 6;
                    }
                }
            } else {
                if (s[i + 1] != '*') {
                    // * num
                    // i  i+1
                    if (s[i + 1] <= '6') {
                        ans += f1(s, i + 2) * 2;
                    } else {
                        ans += f1(s, i + 2);
                    }
                } else {
                    // * *
                    // i  i+1
                    // 11 12 ... 19 21 22 ... 26 -> 一共15种可能
                    // 没有10、20，因为*只能变1~9，并不包括0
                    ans += f1(s, i + 2) * 15;
                }
            }
        }
        return ans;
    }

    // 暴力尝试改记忆化搜索
    int numDecodings2(const string& s) {
        vector<long long> dp(s.length(), -1);
        return (int)f2(s, 0, dp);
    }

    long long f2(const string& s, int i, vector<long long>& dp) {
        int n = s.length();
        if (i == n) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        long long ans = f2(s, i + 1, dp) * (s[i] == '*' ? 9 : 1);
        if (i + 1 < n) {
            if (s[i] != '*') {
                if (s[i + 1] != '*') {
                    if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                        ans += f2(s, i + 2, dp);
                    }
                } else {
                    if (s[i] == '1') {
                        ans += f2(s, i + 2, dp) * 9;
                    }
                    if (s[i] == '2') {
                        ans += f2(s, i + 2, dp) * 6;
                    }
                }
            } else {
                if (s[i + 1] != '*') {
                    if (s[i + 1] <= '6') {
                        ans += f2(s, i + 2, dp) * 2;
                    } else {
                        ans += f2(s, i + 2, dp);
                    }
                } else {
                    ans += f2(s, i + 2, dp) * 15;
                }
            }
        }
        ans %= MOD;
        dp[i] = ans;
        return ans;
    }

    // 严格位置依赖的动态规划
    int numDecodings3(const string& s) {
        int n = s.length();
        vector<long long> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                dp[i] = (s[i] == '*' ? 9 : 1) * dp[i + 1];
                if (i + 1 < n) {
                    if (s[i] != '*') {
                        if (s[i + 1] != '*') {
                            if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                                dp[i] += dp[i + 2];
                            }
                        } else {
                            if (s[i] == '1') {
                                dp[i] += dp[i + 2] * 9;
                            }
                            if (s[i] == '2') {
                                dp[i] += dp[i + 2] * 6;
                            }
                        }
                    } else {
                        if (s[i + 1] != '*') {
                            if (s[i + 1] <= '6') {
                                dp[i] += dp[i + 2] * 2;
                            } else {
                                dp[i] += dp[i + 2];
                            }
                        } else {
                            dp[i] += dp[i + 2] * 15;
                        }
                    }
                }
                dp[i] %= MOD;
            }
        }
        return (int)dp[0];
    }

    // 严格位置依赖的动态规划 + 空间压缩
    int numDecodings4(const string& s) {
        int n = s.length();
        long long cur = 0, nxt = 1, nextNext = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                cur = (s[i] == '*' ? 9 : 1) * nxt;
                if (i + 1 < n) {
                    if (s[i] != '*') {
                        if (s[i + 1] != '*') {
                            if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                                cur += nextNext;
                            }
                        } else {
                            if (s[i] == '1') {
                                cur += nextNext * 9;
                            }
                            if (s[i] == '2') {
                                cur += nextNext * 6;
                            }
                        }
                    } else {
                        if (s[i + 1] != '*') {
                            if (s[i + 1] <= '6') {
                                cur += nextNext * 2;
                            } else {
                                cur += nextNext;
                            }
                        } else {
                            cur += nextNext * 15;
                        }
                    }
                }
                cur %= MOD;
            }
            nextNext = nxt;
            nxt = cur;
            cur = 0;
        }
        return (int)nxt;
    }
};
```

---


**核心套路:** 
- **一维线性 DP + 分类讨论**：当前字符的解码方案数，等于“当前字符单独解码的方案数（依赖 `i+1`）” 加上 “当前字符与后一个字符组合解码的方案数（依赖 `i+2`）”。
    
- **乘法原理与加法原理结合**：遇到 `*` 号时，将 `*` 视为一种**组合系数**（如 `**` 的系数是 15，`*6` 的系数是 2），将其与子问题的结果相乘，再将各种有效组合的方案数相加。
    
- **空间压缩（滚动变量）**：因为 `dp[i]` 严格只依赖 `dp[i+1]` 和 `dp[i+2]`，所以可以将 $O(N)$ 的空间压缩到 $O(1)$，只需要维护 `cur`、`nxt` 和 `nextNext` 三个指针/变量即可。
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
