# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**难度 [[]]


```cpp
// 065 Code03 Bellman-Ford算法应用（不是模版）

// k站中转内最便宜的航班
// 有 n 个城市通过一些航班连接。给你一个数组 flights
// 其中 flights[i] = [fromi, toi, pricei]
// 表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。
// 现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线
// 使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。
// 测试链接 : https://leetcode.cn/problems/cheapest-flights-within-k-stops/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Bellman-Ford算法
    // 针对此题改写了松弛逻辑，课上讲了细节
    int findCheapestPrice(int n, vector<vector<int>>& flights, int start, int target, int k) {
        vector<int> cur(n, INT_MAX);
        cur[start] = 0;
        
        // 限制最多经过 k 站，相当于最多走 k + 1 条边
        for (int i = 0; i <= k; i++) {
            // C++ 中 vector 的直接赋值就是深拷贝
            // 命名为 nxt 避免与 std::next 发生命名冲突
            vector<int> nxt = cur;
            
            for (const auto& edge : flights) {
                // a -> b , w
                if (cur[edge[0]] != INT_MAX) {
                    nxt[edge[1]] = min(nxt[edge[1]], cur[edge[0]] + edge[2]);
                }
            }
            // 将更新后的状态赋给 cur 供下一轮使用
            cur = nxt;
        }
        
        return cur[target] == INT_MAX ? -1 : cur[target];
    }
};
```

---


**核心套路:** 
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
