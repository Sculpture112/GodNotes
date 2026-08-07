# []

> **原题链接:** ()

**涉及知识点:** [[并查集]], [[构造]]，[[补题]],[[BFS]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    int s = -1; // 任选一个 a[i] = 0 的点作为起点

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0 && s == -1) {
            s = i;
        }
    }

    vector<vector<int>> graph(n + 1);
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 起点到自己的距离必须为 0。
    if (s == -1) {
        cout << -1 << '\n';
        return 0;
    }

    /*
        把每条无向边临时按 a 值方向理解：

        若 a[u] <= a[v]，可以从 u 向 v 扩展。
        因为最短路从起点向外走时，距离不能下降。

        BFS 只是在检查：
        是否能从 s 出发，经由 a 值不减的路径到达每个点。
    */
    vector<bool> visited(n + 1, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    int reached = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            // 只允许从目标距离较小/相等的点走向较大/相等的点。
            if (!visited[v] && a[v] >= a[u]) {
                visited[v] = true;
                ++reached;
                q.push(v);
            }
        }
    }

    // 存在某个点不能通过 a 不减路径到达，则无解。
    if (reached != n) {
        cout << -1 << '\n';
        return 0;
    }

    /*
        验证通过后，对每条边直接赋权为两端目标距离之差：

        w = |a[u] - a[v]|

        这既不会制造更短路径，
        又能让 BFS 找到的 a 不减路径恰好累加到目标距离。
    */
    for (auto [u, v] : edges) {
        cout << abs(a[u] - a[v]) << '\n';
    }

    return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa, sz;

    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
	}
	/*
fa[0]=0
fa[1]=1
fa[2]=2
...
fa[n]=n
	*/

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> edges(m);
    for (auto &[u, v] : edges) {
        cin >> u >> v;
    }

    // 第 1 步：通过相等 a 值的边，把点合成零权连通块
    DSU dsu(n);
    for (auto [u, v] : edges) {
        if (a[u] == a[v]) {
            dsu.merge(u, v);
        }
    }

    // 第 2 步：记录每个块是否有一条边通向更小的 a 值
    vector<bool> hasLower(n + 1, false);

    for (auto [u, v] : edges) {
        int ru = dsu.find(u);
        int rv = dsu.find(v);

        if (a[u] > a[v]) {
            hasLower[ru] = true;
        } else if (a[v] > a[u]) {
            hasLower[rv] = true;
        }
    }

    // 第 3 步：检查唯一零值块，以及每个正值块能否向下走
    int zeroBlockCount = 0;
    bool ok = true;

    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) != i) continue; // 只检查每个块的代表元

        if (a[i] == 0) {
            zeroBlockCount++;
        } else if (!hasLower[i]) {
            ok = false;
        }
    }

    if (zeroBlockCount != 1) {
        ok = false;
    }

    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    // 第 4 步：构造边权
    for (auto [u, v] : edges) {
        cout << abs(a[u] - a[v]) << '\n';
    }

    return 0;
}
```

---


