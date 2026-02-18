// 049 Code01 累加和大于等于 target 的最短子数组长度
// 测试链接 : https://leetcode.cn/problems/minimum-size-subarray-sum/
// 核心：滑动窗口。利用数组全是正数带来的单调性。

# include <iostream>

# include <vector>

# include <algorithm>

# include <climits>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    // sum维护的是窗口 [l, r] 内的累加和
    for (int l = 0, r = 0, sum = 0; r < n; r++) {
        sum += nums[r];

        // 左神风格：如果剔除左边界依然达标，则缩窄窗口
        // 这样可以保证每次 r 停止移动时，[l, r] 是以 r 结尾且满足条件的最短区间
        while (sum - nums[l] >= target) {
            sum -= nums[l++];
        }

        if (sum >= target) {
            ans = min(ans, r - l + 1);
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    // 子数组 [4, 3] 长度为 2
    printf("最小子数组长度: %d\n", minSubArrayLen(target, nums));
    return 0;
}