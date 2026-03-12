
[[拓扑排序]]
[[母题]]
```c++

// 核心思路：拓扑排序 + DAG最长路 (动态规划)
// 时间复杂度 O(n + m)，空间复杂度 O(n + m)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // 1. 建图与入度统计
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        for (auto& rel : relations) {
            graph[rel[0]].push_back(rel[1]);
            indegree[rel[1]]++;
        }

        // 2. 队列初始化：入度为 0 的课程
        vector<int> q(n);
        int l = 0, r = 0;
        // cost[i] 表示完成 i 课程所有先修课的最短时间
        vector<int> cost(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q[r++] = i;
            }
        }

        int ans = 0;
        // 3. 拓扑排序递推
        while (l < r) {
            int u = q[l++];
            // 当前课程完成的总时间 = 先修课最大耗时 + 当前课程耗时
            int totalTimeU = cost[u] + time[u - 1];
            ans = max(ans, totalTimeU);

            for (int v : graph[u]) {
                // 更新后续课程的先修课最大耗时
                cost[v] = max(cost[v], totalTimeU);
                if (--indegree[v] == 0) {
                    q[r++] = v;
                }
            }
        }

        return ans;
    }
};
```