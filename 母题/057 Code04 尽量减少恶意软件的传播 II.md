# []

> **原题链接:** (https://leetcode.cn/problems/minimize-malware-spread-ii/)

**涉及知识点:** [[]], [[]]，[[需重刷]]


```cpp
// 057 Code04 尽量减少恶意软件的传播 II

// 测试链接 : https://leetcode.cn/problems/minimize-malware-spread-ii/
// 核心思路：并查集（只对安全节点操作）。
// 1. 找出所有的初始感染节点，将它们打上标签（virus 数组）。
// 2. 遍历所有的安全节点（非初始感染节点），如果它们之间有边相连，则用并查集将它们合并成一个个连通块。
// 3. 遍历所有的初始感染节点，看它们连接到了哪些安全节点的连通块（通过代表节点标识）。
//    - 如果一个连通块只与一个感染节点相连，那么移除这个感染节点，该连通块就能获救。将感染节点记为该连通块的“独家源头”。
//    - 如果一个连通块与多个不同的感染节点相连，那么移除任何单一感染节点都无法拯救它，将其源头标记为 -2（无药可救）。
// 4. 统计每个感染节点作为“独家源头”能拯救的普通节点总数（即对应连通块的大小）。
// 5. 找出能拯救最多节点的感染节点，若拯救数量相同，优先返回索引最小的节点。
// 时间复杂度 O(N^2)，额外空间复杂度 O(N)

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        
        // virus: 标记某个点是否为初始感染节点
        vector<bool> virus(n, false);
        for (int i : initial) {
            virus[i] = true;
        }
        
        // father: 并查集父节点
        // size: 连通块大小（此处只统计安全节点的连通块）
        vector<int> father(n);
        vector<int> size(n, 1);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
        
        // Lambda 实现带路径压缩的查找
        function<int(int)> find = [&](int i) {
            if (i != father[i]) {
                father[i] = find(father[i]);
            }
            return father[i];
        };
        
        // 极简合并操作
        auto unite = [&](int x, int y) {
            int fx = find(x);
            int fy = find(y);
            if (fx != fy) {
                father[fx] = fy;
                size[fy] += size[fx]; // 累加获救的安全节点数量
            }
        };
        
        // 1. 将所有普通的“安全节点”互相连通
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 && !virus[i] && !virus[j]) {
                    unite(i, j);
                }
            }
        }
        
        // infect: 标记每个连通块的感染源头
        // -1: 目前暂无源头
        // >=0: 目前该连通块有唯一源头（节点编号）
        // -2: 该连通块有不止一个源头，已经无法拯救
        vector<int> infect(n, -1);
        
        // 2. 遍历感染节点，寻找被它们直接连接的安全连通块
        for (int sick : initial) {
            for (int neighbor = 0; neighbor < n; neighbor++) {
                // 如果当前感染节点和某个安全节点相连
                if (sick != neighbor && !virus[neighbor] && graph[sick][neighbor] == 1) {
                    int fn = find(neighbor);
                    if (infect[fn] == -1) {
                        infect[fn] = sick; // 第一次发现源头
                    } else if (infect[fn] != -2 && infect[fn] != sick) {
                        infect[fn] = -2;   // 发现了其他源头，彻底没救了
                    }
                }
            }
        }
        
        // cnts: 每个初始感染节点删掉后，能拯救的总节点数
        vector<int> cnts(n, 0);
        
        // 3. 统计拯救数据
        for (int i = 0; i < n; i++) {
            // 只看每个连通块的代表节点
            if (i == find(i) && infect[i] >= 0) {
                cnts[infect[i]] += size[i];
            }
        }
        
        // 4. 对初始感染节点排序，以保证在拯救数量相同时优先返回较小索引
        sort(initial.begin(), initial.end());
        int ans = initial[0];
        int max_saved = cnts[ans];
        
        for (int i : initial) {
            if (cnts[i] > max_saved) {
                ans = i;
                max_saved = cnts[i];
            }
        }
        
        return ans;
    }
};
```

---


**核心套路:** [[]]
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
