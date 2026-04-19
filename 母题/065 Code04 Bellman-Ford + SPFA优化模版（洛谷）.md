# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3385)

**涉及知识点:** [[已AC]], [[Bellman-Ford]]，[[需重刷]],[[单源最短路径]],[[SPFA]],[[链式前向星]]，[[负环]]

**难度 [[]]


```cpp
// 065 Code04 Bellman-Ford + SPFA优化模版（洛谷）

// 给定n个点的有向图，请求出图中是否存在从顶点1出发能到达的负环
// 负环的定义是：一条边权之和为负数的回路
// 测试链接 : https://www.luogu.com.cn/problem/P3385
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// C++ 提交时直接全部复制提交即可通过

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 2005;
// 最多 3000 条边，并且可能建双向边，所以开 6005
const int MAXM = 6005;

// 链式前向星建图需要
int head[MAXN];
int nxt[MAXM]; // 避免与 std::next 冲突
int to_node[MAXM]; // 避免过于泛化
int weight[MAXM];
int cnt;

// SPFA 需要
const int MAXQ = 4000005;

// 源点出发到每个节点的距离表
int dist[MAXN]; // 避免与 std::distance 冲突

// 节点被松弛的次数
int updateCnt[MAXN];

// 哪些节点被松弛了放入队列
int q[MAXQ];
int l_ptr, r_ptr;

// 节点是否已经在队列中
bool enter_q[MAXN];

void build(int n) {
    cnt = 1;
    l_ptr = r_ptr = 0;
    fill(head + 1, head + n + 1, 0);
    fill(enter_q + 1, enter_q + n + 1, false);
    fill(dist + 1, dist + n + 1, INT_MAX);
    fill(updateCnt + 1, updateCnt + n + 1, 0);
}

void addEdge(int u, int v, int w) {
    nxt[cnt] = head[u];
    to_node[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}

// Bellman-Ford + SPFA优化的模版
bool spfa(int n) {
    dist[1] = 0;
    updateCnt[1]++;
    q[r_ptr++] = 1;
    enter_q[1] = true;
    
    while (l_ptr < r_ptr) {
        int u = q[l_ptr++];
        enter_q[u] = false;
        
        for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
            int v = to_node[ei];
            int w = weight[ei];
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!enter_q[v]) {
                    // 松弛次数超过 n-1 就有负环
                    if (++updateCnt[v] > n - 1) {
                        return true;
                    }
                    q[r_ptr++] = v;
                    enter_q[v] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    // C++ 的快速 I/O 模板，极大提升读写效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    if (cin >> cases) {
        for (int i = 0; i < cases; i++) {
            int n, m;
            cin >> n >> m;
            build(n);
            
            for (int j = 0; j < m; j++) {
                int u, v, w;
                cin >> u >> v >> w;
                if (w >= 0) {
                    addEdge(u, v, w);
                    addEdge(v, u, w);
                } else {
                    addEdge(u, v, w);
                }
            }
            
            if (spfa(n)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
```

---


**核心套路:** 
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
