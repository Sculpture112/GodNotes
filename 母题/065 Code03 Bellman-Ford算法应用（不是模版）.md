# []

> **原题链接:** (https://leetcode.cn/problems/cheapest-flights-within-k-stops/)

**涉及知识点:** [[已AC]], [[Bellman-Ford]]，[[需重刷]],[[DP]],[[单源最短路径]]

**难度 [[超难]]


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
/**❌ 如果不用 `nxt`，直接在 `cur` 上改（会发生“串联”）：**

1. 遍历到 A $\rightarrow$ B：查到 A 是 0，于是把 `cur[B]` 更新成了 100。
    
2. 紧接着遍历到 B $\rightarrow$ C：查到 `cur[B]` 已经是 100 了（**刚刚被更新的！**），于是顺手把 `cur[C]` 更新成了 100 + 100 = 200。
    

- **灾难发生**：明明只让飞 1 段，你却在同一轮里一口气从 A 飞到了 C。如果题目限制只能飞 1 段，C 其实是不可达的，但你的代码却认为到达 C 花费 200。
    

**✅ 如果用了 `nxt` 隔离状态（当前代码的逻辑）：**

1. 遍历到 A $\rightarrow$ B：查旧表 `cur[A]` 是 0，把新表 `nxt[B]` 更新为 100。此时旧表 `cur[B]` 依然是无穷大。
    
2. 紧接着遍历到 B $\rightarrow$ C：查旧表 `cur[B]`，发现还是无穷大！说明在上一轮我们根本还没到达 B，自然无法从 B 起飞。跳过更新。
    

- **结果正确**：第 1 轮结束时，只有 B 被更新了，C 依然不可达。完美符合“只飞 1 段”的限制。*/
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
1. 转化条件：“最多经过 k 站中转” 等价于 “从起点出发最多走 k+1 条边”。
2. 限制层数的动态规划：本质是求解 dp[i][v] = min(dp[i-1][v], dp[i-1][u] + weight(u, v))。
3. 状态隔离（滚动数组防串联）：在将二维 DP 压缩为一维时，为了保证当前轮次（第 i 步）的状态只依赖上一轮（第 i-1 步）的历史状态，必须引入 `nxt` 数组进行隔离。如果不隔离，就会发生一轮内连走多步的“污染”。
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
