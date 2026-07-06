# [082 Code02 买卖股票的最佳时机 II]

> **原题链接:** (https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

**涉及知识点:** [[已AC]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

// 买卖股票的最佳时机 II
// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格
// 在每一天，你可以决定是否购买和/或出售股票
// 你在任何时候 最多 只能持有 一股 股票
// 你也可以先购买，然后在 同一天 出售
// 返回 你能获得的 最大 利润
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            ans += max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }
};
```

---

