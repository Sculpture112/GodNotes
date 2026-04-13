# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**难度 [[]]


```cpp
// 066 Code05 丑数 II

// 给你一个整数 n ，请你找出并返回第 n 个 丑数
// 丑数 就是只包含质因数 2、3 或 5 的正整数
// 测试链接 : https://leetcode.cn/problems/ugly-number-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 时间复杂度 O(n)，n 代表第 n 个丑数
    int nthUglyNumber(int n) {
        // dp 0 1 2 ...  n
        //      1 2 ...  ?
        vector<int> dp(n + 1);
        dp[1] = 1;
        
        for (int i = 2, i2 = 1, i3 = 1, i5 = 1; i <= n; i++) {
            int a = dp[i2] * 2;
            int b = dp[i3] * 3;
            int c = dp[i5] * 5;
            
            // C++11 支持使用初始化列表求多个值的最小/最大值
            int cur = min({a, b, c});
            
            // 注意这里是三个独立的 if，不是 else if
            // 因为 a, b, c 可能存在相同的值，需要同时指针后移去重
            if (cur == a) {
                i2++;
            }
            if (cur == b) {
                i3++;
            }
            if (cur == c) {
                i5++;
            }
            dp[i] = cur;
        }
        
        return dp[n];
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
