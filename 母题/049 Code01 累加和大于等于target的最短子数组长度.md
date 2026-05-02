# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
// 049 Code01 累加和大于等于target的最短子数组长度

// 给定一个含有 n 个正整数的数组和一个正整数 target
// 找到累加和 >= target 的长度最小的子数组并返回其长度
// 如果不存在符合条件的子数组返回0
// 测试链接 : https://leetcode.cn/problems/minimum-size-subarray-sum/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // 时间复杂度O(n)，额外空间复杂度O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        
        // 滑动窗口：l 为左边界，r 为右边界，sum 为窗口内元素的累加和
        for (int l = 0, r = 0, sum = 0; r < n; r++) {
            sum += nums[r];
            
            // 只要减去左边界的值后依然满足 sum >= target，就不断收缩窗口
            // 这样可以保证窗口在满足条件的前提下尽可能短
            while (sum - nums[l] >= target) {
                sum -= nums[l++];
            }
            
            // 检查当前窗口是否达标
            if (sum >= target) {
                ans = min(ans, r - l + 1);
            }
        }
        
        // 如果 ans 还是初始值，说明没有找到符合条件的子数组
        return ans == INT_MAX ? 0 : ans;
    }
};
```

---


