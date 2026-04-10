# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**难度 [[]]


```cpp
// 064 Code01 Dijkstra算法模版（Leetcode）

// 网络延迟时间
// 有 n 个网络节点，标记为 1 到 n
// 给你一个列表 times，表示信号经过 有向 边的传递时间
// times[i] = (ui, vi, wi)，表示从ui到vi传递信号的时间是wi
// 现在，从某个节点 s 发出一个信号
// 需要多久才能使所有节点都收到信号
// 如果不能使所有节点收到信号，返回 -1
// 测试链接 : https://leetcode.cn/problems/network-delay-time

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// 链式前向星和反向索引堆需要的静态全局数组
const int MAXN = 105;
const int MAXM = 6005;

// 链式前向星
int head[MAXN];
int nxt[MAXM]; // 避免与 std::next 冲突
int to_node[MAXM]; // 避免命名过于泛化，使用 to_node
int weight[MAXM];
int cnt;

// 反向索引堆
int heap_arr[MAXN]; // 避免与 std::make_heap 等概念冲突

// where[v] = -1，表示v这个节点，从来没有进入过堆
// where[v] = -2，表示v这个节点，已经弹出过了
// where[v] = i(>=0)，表示v这个节点，在堆上的i位置
int where[MAXN];
int heapSize;
int dist[MAXN];

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 解法1和解法2调用哪一个都可以
        // return networkDelayTime1(times, n, k);
        return networkDelayTime2(times, n, k);
    }

    // ================= 解法1 ================= 
    // 动态建图 + 普通堆的实现
    int networkDelayTime1(vector<vector<int>>& times, int n, int s) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        
        vector<int> distance(n + 1, INT_MAX);
        distance[s] = 0;
        vector<bool> visited(n + 1, false);
        
        // 优先队列，元素格式为 pair<距离, 节点>，使用 greater 实现小根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        
        while (!pq.empty()) {
            // C++17 结构化绑定提取距离和节点
            auto [d, u] = pq.top();
            pq.pop();
            
            if (visited[u]) {
                continue;
            }
            visited[u] = true;
            
            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;
                if (!visited[v] && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    pq.push({distance[v], v});
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, distance[i]);
        }
        return ans;
    }

    // ================= 解法2 ================= 
    // 链式前向星 + 反向索引堆的实现
    int networkDelayTime2(vector<vector<int>>& times, int n, int s) {
        build(n);
        for (const auto& edge : times) {
            addEdge(edge[0], edge[1], edge[2]);
        }
        addOrUpdateOrIgnore(s, 0);
        while (!isEmpty()) {
            int u = pop_heap();
            for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
                addOrUpdateOrIgnore(to_node[ei], dist[u] + weight[ei]);
            }
        }
        
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }

    void build(int n) {
        cnt = 1;
        heapSize = 0;
        fill(head + 1, head + n + 1, 0);
        fill(where + 1, where + n + 1, -1);
        fill(dist + 1, dist + n + 1, INT_MAX);
    }

    // 链式前向星建图
    void addEdge(int u, int v, int w) {
        nxt[cnt] = head[u];
        to_node[cnt] = v;
        weight[cnt] = w;
        head[u] = cnt++;
    }

    void addOrUpdateOrIgnore(int v, int c) {
        if (where[v] == -1) {
            heap_arr[heapSize] = v;
            where[v] = heapSize++;
            dist[v] = c;
            heapInsert(where[v]);
        } else if (where[v] >= 0) {
            dist[v] = min(dist[v], c);
            heapInsert(where[v]);
        }
    }

    void heapInsert(int i) {
        while (dist[heap_arr[i]] < dist[heap_arr[(i - 1) / 2]]) {
            swap_heap(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    // 命名为 pop_heap 避免和系统函数冲突
    int pop_heap() {
        int ans = heap_arr[0];
        swap_heap(0, --heapSize);
        heapify(0);
        where[ans] = -2;
        return ans;
    }

    void heapify(int i) {
        int l = i * 2 + 1;
        while (l < heapSize) {
            int best = l + 1 < heapSize && dist[heap_arr[l + 1]] < dist[heap_arr[l]] ? l + 1 : l;
            best = dist[heap_arr[best]] < dist[heap_arr[i]] ? best : i;
            if (best == i) {
                break;
            }
            swap_heap(best, i);
            i = best;
            l = i * 2 + 1;
        }
    }

    bool isEmpty() {
        return heapSize == 0;
    }

    // 专门为反向索引堆写的交换函数
    void swap_heap(int i, int j) {
        int tmp = heap_arr[i];
        heap_arr[i] = heap_arr[j];
        heap_arr[j] = tmp;
        where[heap_arr[i]] = i;
        where[heap_arr[j]] = j;
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
