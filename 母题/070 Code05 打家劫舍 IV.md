# []

> **原题链接:** (https://leetcode.cn/problems/house-robber-iv/)

**涉及知识点:** [[已AC]], [[DP]]，[[需重刷]],[[]],[[]]

**核心套路:** 


```cpp
// 070 Code05 打家劫舍 IV

// 沿街有一排连续的房屋。每间房屋内都藏有一定的现金
// 现在有一位小偷计划从这些房屋中窃取现金
// 由于相邻的房屋装有相互连通的防盗系统，所以小偷不会窃取相邻的房屋
// 小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额
// 给你一个整数数组 nums 表示每间房屋存放的现金金额
// 第i间房屋中放有nums[i]的钱数
// 另给你一个整数k，表示小偷需要窃取至少 k 间房屋
// 返回小偷需要的最小窃取能力值
// 测试链接 : https://leetcode.cn/problems/house-robber-iv/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = nums[0];
        int r = nums[0];
        
        for (int i = 1; i < n; i++) {
            l = min(l, nums[i]);
            r = max(r, nums[i]);
        }
        
        // l....r 范围内二分答案
        int m, ans = 0;
        while (l <= r) {
            // 防溢出的写法
            m = l + (r - l) / 2;
            
            // 三种检验方法任选其一均可，推荐使用最快的贪心 mostRob3
            // if (mostRob1(nums, n, m) >= k) {
            // if (mostRob2(nums, n, m) >= k) {
            if (mostRob3(nums, n, m) >= k) {
                ans = m;
                // 能达标，尝试寻找更小的能力值
                r = m - 1;
            } else {
                // 不能达标，能力值必须更大
                l = m + 1;
            }
        }
        return ans;
    }

    // 盗贼能力为 ability 时
    // 返回盗贼最多能窃取多少间房屋
    // 注意限制 : 不能窃取相邻房屋，且只能窃取 <= ability 的房屋
    // 动态规划版本
    int mostRob1(const vector<int>& nums, int n, int ability) {
        if (n == 1) {
            return nums[0] <= ability ? 1 : 0;
        }
        if (n == 2) {
            return (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        }
        
        vector<int> dp(n);
        dp[0] = nums[0] <= ability ? 1 : 0;
        dp[1] = (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], (nums[i] <= ability ? 1 : 0) + dp[i - 2]);
        }
        return dp[n - 1];
    }

    // 继续空间压缩优化
    int mostRob2(const vector<int>& nums, int n, int ability) {
        if (n == 1) {
            return nums[0] <= ability ? 1 : 0;
        }
        if (n == 2) {
            return (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        }
        
        int prepre = nums[0] <= ability ? 1 : 0;
        int pre = (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        
        for (int i = 2; i < n; i++) {
            int cur = max(pre, (nums[i] <= ability ? 1 : 0) + prepre);
            prepre = pre;
            pre = cur;
        }
        return pre;
    }

    // 继续贪心优化
    // 因为所有房屋的权重实际上变成了 1（选了就算1间），所以只要遇到满足 <= ability 的能偷就立刻偷，收益一定最大
    int mostRob3(const vector<int>& nums, int n, int ability) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= ability) {
                ans++;
                // 偷了当前这间，下一间相邻的肯定不能偷，直接跳过
                i++;
            }
        }
        return ans;
    }
};
```

---



**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
