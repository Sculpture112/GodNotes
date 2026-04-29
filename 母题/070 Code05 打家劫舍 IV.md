# []

> **原题链接:** (https://leetcode.cn/problems/house-robber-iv/)

**涉及知识点:** [[已AC]], [[DP]]，[[需重刷]],[[二分答案法]],[[贪心算法]]

**核心套路:** 
1. **“最大值最小化”标准范式：** 题目要求“求最小的窃取能力（即所偷房屋中的最大金额）”，看到“最小化最大值”**或**“最大化最小值”**的字眼，直接条件反射采用**二分答案。 
2. **二分值域：** 窃取能力的取值下限是数组中的最小值 `min(nums)`，上限是数组中的最大值 `max(nums)`。在这个值域上进行二分查找。 
3. **校验函数（Check）的降维转化：** 将最优化问题转化为判定性问题——“当盗贼能力限制为 `m` 时，能否在不触动警报的情况下，偷到至少 `k` 间房子？”。
4. **贪心对 DP 的降维打击（一题多解的核心）：** * **DP视角：** 这是一个带有条件限制的《打家劫舍》模型。 * **贪心视角（最优解）：** 因为校验函数中，所有的房屋价值被拉平了（只要金额 $\le m$，偷它就算作 $1$ 间房）。在权重全为 $1$ 的前提下，**遇到能偷的立刻偷，并强行跳过下一间**，这种贪心策略不仅能拿到最多的房间数，而且将额外空间复杂度从 $O(N)$ 降到了 $O(1)$。


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
