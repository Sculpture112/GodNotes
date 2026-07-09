# []

> **原题链接:** (https://leetcode.cn/problems/parallel-courses-iii/)

**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]

**核心套路:** 

## 破题切入点(思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// 并行课程 III
// 给你一个整数 n ，表示有 n 节课，课程编号从 1 到 n
// 同时给你一个二维整数数组 relations ，
// 其中 relations[j] = [prevCoursej, nextCoursej]
// 表示课程 prevCoursej 必须在课程 nextCoursej 之前 完成（先修课的关系）
// 同时给你一个下标从 0 开始的整数数组 time
// 其中 time[i] 表示完成第 (i+1) 门课程需要花费的 月份 数。
// 请你根据以下规则算出完成所有课程所需要的 最少 月份数：
// 如果一门课的所有先修课都已经完成，你可以在 任意 时间开始这门课程。
// 你可以 同时 上 任意门课程 。请你返回完成所有课程所需要的 最少 月份数。
// 注意：测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）
// 测试链接 : https://leetcode.cn/problems/parallel-courses-iii/
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // 点 : 1....n
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        for (vector<int>& edge : relations) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        vector<int> queueArr(n);
        int l = 0;
        int r = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                queueArr[r++] = i;
            }
        }
        vector<int> cost(n + 1, 0);
        int ans = 0;
        while (l < r) {
            int cur = queueArr[l++];
            // 1 : time[0]
            // x : time[x-1]
            cost[cur] += time[cur - 1];
            ans = max(ans, cost[cur]);
            for (int next : graph[cur]) {
                cost[next] = max(cost[next], cost[cur]);
                if (--indegree[next] == 0) {
                    queueArr[r++] = next;
                }
            }
        }
        return ans;
    }
};
```

---

