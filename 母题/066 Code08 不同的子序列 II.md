# []

> **原题链接:** (https://leetcode.cn/problems/distinct-subsequences-ii/)

**涉及知识点:** [[一维DP]], [[已AC]]，[[需重刷]],[[]],[[]]

**难度 [[]]


```cpp
// 066 Code08 不同的子序列 II

// 给定一个字符串 s，计算 s 的 不同非空子序列 的个数
// 因为结果可能很大，答案对 1000000007 取模
// 字符串的 子序列 是经由原字符串删除一些（也可能不删除）
// 字符但不改变剩余字符相对位置的一个新字符串
// 例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是
// 测试链接 : https://leetcode.cn/problems/distinct-subsequences-ii/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 时间复杂度 O(n)，n 是字符串 s 的长度
    int distinctSubseqII(string s) {
        int mod = 1000000007;
        
        // 记录必须以某字符结尾的子序列数量
        // 自动初始化为 0
        vector<int> cnt(26, 0);
        
        // all 表示当前拥有的总子序列数，初始包含 1 个空集
        int all = 1;
        int newAdd;
        
        // C++ 的 string 支持直接利用范围 for 循环遍历
        for (char x : s) {
            // 新增的子序列数量 = 之前所有的子序列数量 - 之前已经以该字符结尾的子序列数量
            // + mod 是为了防止减法产生负数
            newAdd = (all - cnt[x - 'a'] + mod) % mod;
            
            // 更新以该字符结尾的子序列数量
            cnt[x - 'a'] = (cnt[x - 'a'] + newAdd) % mod;
            
            // 更新所有的子序列数量
            all = (all + newAdd) % mod;
        }
        
        // 最后减去初始的那个空集，同样需要防负数
        return (all - 1 + mod) % mod;
    }
};
```

---


**核心套路:** 
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
