```cpp
给定一个整数序列 a=[a1,a2,…,an]a=[a1​,a2​,…,an​] 和目标整数 TT，寻找一对下标 (i,j)(i,j) 满足 1≦i<j≦n1≦i<j≦n 且 ai+aj=Tai​+aj​=T。测试数据保证恰有一组解，你需要求出对应的下标对 (i,j)(i,j) 作为序列并返回。传入参数：∙ ∙整数序列 aa，长度满足 2≦n≦1052≦n≦105 且 0≦ai≦1090≦ai​≦109；∙ ∙目标整数 TT，满足 0≦T≦1090≦T≦109。返回值：一对整数下标 (i,j)(i,j) 构成的序列，满足 ai+aj=Tai​+aj​=T。示例1输入：[0,7,2,1],9
```
复制

返回值：
```cpp
[2,3]
```
复制

说明：
```cpp
a2+a3=7+2=9a2​+a3​=7+2=9。
```

```cpp
class Solution {
public:
    /**
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        // key: 数值, value: 在原数组中的 1-based 下标
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // 如果在 map 中找到了需要的补数
            if (mp.find(complement) != mp.end()) {
                // 返回之前的下标和当前下标 (都要 +1 转换成 1-based)
                // 题目要求 i < j，mp[complement] 存储的是之前出现的，所以它一定更小
                return {mp[complement], i + 1};
            }

            // 存入当前数值及其 1-based 下标
            mp[nums[i]] = i + 1;
        }

        return {}; // 理论上不会执行
    }
};
```