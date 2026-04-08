# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3366)

**涉及知识点:** [[]], [[]]，[[需重刷]]


```cpp
// 061 Code01 Kruskal算法模版 & 最小生成树(洛谷)

// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 核心思路：贪心 + 并查集。
// 1. 把所有边按照权重从小到大排序。
// 2. 从权重最小的边开始遍历，利用并查集判断这条边的两个端点是否已经在同一个连通块中。
// 3. 如果不在同一个连通块，说明这条边不会构成环，将其加入最小生成树，并合并这两个端点。
// 4. 当成功加入 N-1 条边时，最小生成树构建完成。
// 时间复杂度 O(M log M)，空间复杂度 O(N + M)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

// 定义边结构体，并重载小于号以便排序
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class KruskalSolution {
private:
    vector<int> father;

    int find(int i) {
        if (i != father[i]) {
            father[i] = find(father[i]); // 路径压缩
        }
        return father[i];
    }

    bool unite(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            return true;
        }
        return false;
    }

public:
    void solve(int n, int m, vector<Edge>& edges) {
        father.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            father[i] = i;
        }

        // 1. 按权重从小到大排序
        sort(edges.begin(), edges.end());

        int ans = 0;
        int edgeCnt = 0;
        
        // 2. 遍历边，尝试合并
        for (const auto& edge : edges) {
            if (unite(edge.u, edge.v)) {
                edgeCnt++;
                ans += edge.w;
                // 优化：找齐 n-1 条边就可以提前退出了
                if (edgeCnt == n - 1) break; 
            }
        }

        if (edgeCnt == n - 1) {
            printf("%d\n", ans);
        } else {
            printf("orz\n");
        }
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
