# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
// 050 Code01 按奇偶排序数组II

// 给定一个非负整数数组 nums。nums 中一半整数是奇数 ，一半整数是偶数
// 对数组进行排序，以便当 nums[i] 为奇数时，i 也是奇数
// 当 nums[i] 为偶数时， i 也是 偶数
// 测试链接 : https://leetcode.cn/problems/sort-array-by-parity-ii/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 时间复杂度 O(n)：每个元素最多被移动一次到其最终位置。
     * 额外空间复杂度 O(1)：仅使用了常数个指针变量。
     */
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        // odd : 当前待填充的奇数下标位置，从 1 开始，每次跳 2
        // even: 当前待填充的偶数下标位置，从 0 开始，每次跳 2
        // 利用数组最后一个元素 nums[n-1] 作为“中转站”进行交换判断
        for (int odd = 1, even = 0; odd < n && even < n; ) {
            // 检查中转站（最后一个数）的奇偶性
            if (nums[n - 1] & 1) {
                // 如果是奇数，将其交换到当前的 odd 位置，odd 下标向后跳 2 位
                swap(nums[odd], nums[n - 1]);
                odd += 2;
            } else {
                // 如果是偶数，将其交换到当前的 even 位置，even 下标向后跳 2 位
                swap(nums[even], nums[n - 1]);
                even += 2;
            }
        }
        return nums;
    }
};
```

---


