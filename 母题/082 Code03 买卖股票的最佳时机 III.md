# [082 Code03 买卖股票的最佳时机 III]

> **原题链接:** (https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

// 买卖股票的最佳时机 III
// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易
// 注意：你不能同时参与多笔交易，你必须在再次购买前出售掉之前的股票
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp1 = 0;
        int best = -prices[0];
        int ans = 0;
        for (int i = 1, mn = prices[0]; i < (int)prices.size(); i++) {
            mn = min(mn, prices[i]);
            dp1 = max(dp1, prices[i] - mn);
            best = max(best, dp1 - prices[i]);
            ans = max(ans, best + prices[i]);
        }
        return ans;
    }
};
```

---

