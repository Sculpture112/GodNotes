[[算法名/拓扑排序|拓扑排序]]
```cpp
// 059 Code02 拓扑排序 (课程表 II)
// 测试链接 : https://leetcode.cn/problems/course-schedule-ii/
// 核心思路：Kahn 算法（入度表 + 队列）
// 时间复杂度 O(N + M)，N 为课程数，M 为先修关系数
// 空间复杂度 O(N + M)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. 准备邻接表和入度表
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& edge : prerequisites) {
            int to = edge[0];   // 想要修的课
            int from = edge[1]; // 先修课
            graph[from].push_back(to);
            indegree[to]++;
        }

        // 2. 数组模拟队列 (左神风格，追求极致速度)
        vector<int> queue(numCourses);
        int l = 0, r = 0;

        // 3. 将所有入度为 0 的节点入队
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue[r++] = i;
            }
        }

        // 4. 开始拓扑排序
        int cnt = 0;
        while (l < r) {
            int cur = queue[l++];
            cnt++;
            // 遍历当前课的所有后续课程
            for (int next : graph[cur]) {
                // 如果后续课程的入度减为 0，则入队
                if (--indegree[next] == 0) {
                    queue[r++] = next;
                }
            }
        }

        // 5. 检查是否所有课程都处理到了（判断是否有环）
        if (cnt == numCourses) {
            return queue;
        } else {
            return {};
        }
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> pre = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    // 可能的一种输出: [0, 1, 2, 3] 或 [0, 2, 1, 3]
    vector<int> result = sol.findOrder(n, pre);
    
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
```