# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
// 073 Code04 最后一块石头的重量 II

// 有一堆石头，用整数数组 stones 表示，其中 stones[i] 表示第 i 块石头的重量。
// 每一回合，从中选出任意两块石头，然后将它们一起粉碎。
// 假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的结果如下：
// 如果 x == y，那么两块石头都会被完全粉碎；
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
// 最后，最多只会剩下一块石头，返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
// 测试链接 : https://leetcode.cn/problems/last-stone-weight-ii/

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 核心逻辑分析：
     * 这个问题本质上是将所有石头分成两堆（两个集合 S1 和 S2）。
     * 我们希望这两堆石头的总重量尽可能接近。
     * 如果两堆重量分别为 sum(S1) 和 sum(S2)，那么最后剩下的石头重量就是 |sum(S1) - sum(S2)|。
     * 这就转化为了：在总和为 sum 的情况下，寻找一个子集的累加和，使其尽量接近 sum / 2。
     * 
     * 时间复杂度 O(n * sum/2)，其中 n 是石头数量。
     * 额外空间复杂度 O(sum/2)，用于动态规划的一维数组。
     */
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        
        // 我们要在 stones 中选择一些数字，使得它们的累加和尽量接近 sum / 2 且不超过它。
        int target = sum / 2;
        int near_half = near(stones, target);
        
        // 剩下的重量 = (总重 - 较轻的一堆) - 较轻的一堆
        return sum - 2 * near_half;
    }

private:
    /**
     * 在非负数组 nums 中，子序列累加和不超过 t，但最接近 t 的累加和是多少？
     * 标准 01 背包问题：
     * 物品的体积是重量，价值也是重量。
     * 目标：在容量 t 下，最大化价值。
     */
    int near(const vector<int>& nums, int t) {
        // dp[j] 表示在容量为 j 的情况下，能装下的最大重量
        vector<int> dp(t + 1, 0);
        
        for (int num : nums) {
            // 空间压缩：必须从右往左遍历容量，防止同一个物品被多次使用
            for (int j = t; j >= num; j--) {
                // 当前状态 = max(不要当前石头, 要当前石头后的总重)
                dp[j] = max(dp[j], dp[j - num] + num);
            }
        }
        return dp[t];
    }
};
```

---


