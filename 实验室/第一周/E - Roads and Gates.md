# []

> **原题链接:** (https://atcoder.jp/contests/abc463/tasks/abc463_e?lang=en)

**涉及知识点:** [[Dijkstra]], [[优先队列]]，[[补题]],[[已AC]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 62);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll Y;
    cin >> N >> M >> Y;

    int H = N; // 虚拟传送点
    vector<vector<pair<int, ll>>> g(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        ll T;
        cin >> u >> v >> T;
        --u;
        --v;

        g[u].push_back({v, T});
        g[v].push_back({u, T});
    }

    vector<ll> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    for (int i = 0; i < N; i++) {
        g[i].push_back({H, X[i] + Y});
        g[H].push_back({i, X[i]});
    }

    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) continue;

        for (auto [to, cost] : g[v]) {
            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (i > 1) cout << ' ';
        cout << dist[i];
    }
    cout << '\n';

    return 0;
}
```

---


