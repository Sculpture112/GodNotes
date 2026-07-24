# []

> **原题链接:** (https://leetcode.cn/problems/ipo/)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

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
    struct Project {
        int p; // 纯利润
        int c; // 需要的启动金

        Project(int profit, int cost) : p(profit), c(cost) {
        }
    };

    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& cost) {
        int n = profit.size();
        // 需要的启动金小根堆
        // 代表被锁住的项目
        auto cmp1 = [](const Project& a, const Project& b) { return a.c > b.c; };
        priority_queue<Project, vector<Project>, decltype(cmp1)> heap1(cmp1);
        // 利润大根堆
        // 代表被解锁的项目
        auto cmp2 = [](const Project& a, const Project& b) { return a.p < b.p; };
        priority_queue<Project, vector<Project>, decltype(cmp2)> heap2(cmp2);
        for (int i = 0; i < n; i++) {
            heap1.emplace(profit[i], cost[i]);
        }
        while (k > 0) {
            while (!heap1.empty() && heap1.top().c <= w) {
                heap2.push(heap1.top());
                heap1.pop();
            }
            if (heap2.empty()) {
                break;
            }
            w += heap2.top().p;
            heap2.pop();
            k--;
        }
        return w;
    }
};
```

---
