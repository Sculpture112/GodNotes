# [[0]]

> **原题链接:** (https://www.luogu.com.cn/problem/P5905)

**涉及知识点:** [[Johnson 全源最短路]], [[Bellman-Ford]]，[[补题]],[[Dijkstra]],[[负环]],[[多源最短路径]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

**触发条件：**

**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

const int64 INF = (1LL << 62);

struct Edge {
    int from, to;
    int64 weight;
};

struct Arc {
    int to;
    int64 weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    edges.reserve(m);

    vector<vector<Arc>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        int64 w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
        graph[u].push_back({v, w});
    }

    /*
     * 相当于添加虚拟源点 0，并建立：
     * 0 -> i，边权为 0。
     *
     * 因此所有 h[i] 直接初始化为 0 即可，
     * 不需要真的把虚拟边加入图中。
     */
    vector<int64> h(n + 1, 0);

    // Bellman-Ford：求势能 h，并检测负环。
    for (int round = 1; round <= n; ++round) {
        bool updated = false;

        for (const Edge &edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int64 w = edge.weight;

            if (h[v] > h[u] + w) {
                h[v] = h[u] + w;
                updated = true;
            }
        }

        if (!updated) { // 如果某一轮没有更新,说明所有边都已经松弛到极限了
            break;
        }

        // 第 n 轮仍能松弛，说明存在负环。
        if (round == n) {
            cout << -1 << '\n';
            return 0;
        }
    }

    vector<int64> dist(n + 1);

    for (int source = 1; source <= n; ++source) {
        fill(dist.begin(), dist.end(), INF);
        dist[source] = 0;

        priority_queue<
            pair<int64, int>,
            vector<pair<int64, int>>,
            greater<pair<int64, int>>
        > heap;

        heap.push({0, source});

        while (!heap.empty()) {
            auto [currentDistance, u] = heap.top();
            heap.pop();

            if (currentDistance != dist[u]) {
                continue;
            }

            for (const Arc &arc : graph[u]) {
                int v = arc.to;

                // Johnson 重标权：
                // w'(u,v) = w(u,v) + h[u] - h[v]
                int64 newWeight = arc.weight + h[u] - h[v];

                if (dist[v] > currentDistance + newWeight) {
                    dist[v] = currentDistance + newWeight;
                    heap.push({dist[v], v});
                }
            }
        }

        int64 answer = 0;

        for (int vertex = 1; vertex <= n; ++vertex) {
            int64 originalDistance;

            if (dist[vertex] == INF) {
                originalDistance = 1000000000LL;
            } else {
                // 原距离 = 重标权后的距离 - h[source] + h[vertex]
                originalDistance =
                    dist[vertex] - h[source] + h[vertex];
            }

            answer += 1LL * vertex * originalDistance;
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---


