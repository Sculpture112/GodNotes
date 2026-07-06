# [082 Code04 买卖股票的最佳时机 IV]

> **原题链接:** (https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

// 买卖股票的最佳时机 IV
// 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易
// 也就是说，你最多可以买 k 次，卖 k 次
// 注意：你不能同时参与多笔交易，你必须在再次购买前出售掉之前的股票
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    int free(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            ans += max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) {
            return 0;
        }
        if (k >= n / 2) {
            return free(prices);
        }
		vector<int> dp(n, 0);
        for (int i = 1; i <= k; i++) {
            int best = dp[0] - prices[0];
            for (int j = 1; j < n; j++) {
                int tmp = dp[j];
                dp[j] = max(dp[j - 1], best + prices[j]);
                best = max(best, tmp - prices[j]);
            }
        }
        return dp[n - 1];
    }
};
```

---

