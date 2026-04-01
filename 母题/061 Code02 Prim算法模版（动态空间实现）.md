# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]]


```cpp
// 061 Code02 Prim算法模版（动态空间实现）

// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 核心思路：严格对标 Java 版 Prim 算法。
// 使用 vector<vector<pair<int, int>>> 模拟 ArrayList<ArrayList<int[]>> 构建动态邻接表。
// 使用 priority_queue 模拟 PriorityQueue。

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 针对洛谷等平台的快读模板
inline bool read(int &x) {
    x = 0; int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == EOF) return false;
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    return true;
}

int main() {
    int n, m;
    // 持续读取直到 EOF
    while (read(n) && read(m)) {
        // graph[i] 存储点 i 的所有相邻边。
        // 为了方便 C++ 优先队列按花费排序，我们用 pair<int, int>，并将 cost 放在 first，to 放在 second
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            read(u);
            read(v);
            read(w);
            graph[u].push_back({w, v}); // {花费, 到达的节点}
            graph[v].push_back({w, u});
        }
        
        // C++ 的优先队列默认是大根堆，配合 greater 变为小根堆
        // 存储类型为 pair<int, int>，默认按照 first (花费) 升序比较
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        
        // 将 1 号节点相连的所有边加入小根堆
        for (const auto& edge : graph[1]) {
            heap.push(edge);
        }
        
        // 记录哪些节点已经发现过了
        vector<bool> set(n + 1, false);
        set[1] = true;
        int nodeCnt = 1;
        int ans = 0;
        
        while (!heap.empty()) {
            auto current = heap.top();
            heap.pop();
            
            int cost = current.first;
            int next = current.second;
            
            if (!set[next]) {
                nodeCnt++;
                set[next] = true;
                ans += cost;
                
                // 将新解锁的节点的所有相邻边加入小根堆
                for (const auto& e : graph[next]) {
                    heap.push(e);
                }
            }
        }
        
        if (nodeCnt == n) {
            printf("%d\n", ans);
        } else {
            printf("orz\n");
        }
    }
    
    return 0;
}
```

---


**核心套路:** [[]]
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
