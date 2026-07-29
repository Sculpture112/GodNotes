# []

> **原题链接:** (https://leetcode.cn/problems/ipo/)

**涉及知识点:** [[贪心算法]], [[优先队列]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

```cpp
#include <bits/stdc++.h>

using namespace std;

// IPO
// 给你n个项目，对于每个项目i
// 它都有一个纯利润profits[i]
// 和启动该项目需要的最小资本capital[i]
// 最初你的资本为w，当你完成一个项目时，你将获得纯利润，添加到你的总资本中
// 总而言之，从给定项目中选择最多k个不同项目的列表
// 以最大化最终资本，并输出最终可获得的最多资本
// 测试链接 : https://leetcode.cn/problems/ipo/

class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profit,
                             vector<int>& cost) {
        // pair<启动资金, 利润>
        // greater 让启动资金最小的项目在堆顶
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> heap1;

        // 已解锁项目：利润最大者在堆顶
        priority_queue<int> heap2;

        for (int i = 0; i < profit.size(); i++) {
            heap1.push({cost[i], profit[i]});
        }

        while (k-- > 0) {
            // 解锁所有当前资金可以启动的项目
            while (!heap1.empty() && heap1.top().first <= w) {
                heap2.push(heap1.top().second);
                heap1.pop();
            }

            // 没有可做项目
            if (heap2.empty()) {
                break;
            }

            // 做利润最大的项目
            w += heap2.top();
            heap2.pop();
        }

        return w;
    }
};
```

---
