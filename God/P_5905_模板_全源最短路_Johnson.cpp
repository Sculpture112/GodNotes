#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
struct Edge
{
    int u, v, weight;
};
struct Arc
{
    int to;
    int weight;
};
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<Arc>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        graph[u].push_back({v, w});
    }

    vector<int> h(n + 1);

    for (int round = 1; round <= n; round++)
    {
        bool update = false;
        for (auto edge : edges)
        {
            int u = edge.u, v = edge.v, w = edge.weight;
            if (h[u] > h[v] + w)
            {
                h[u] = h[v] + w;
                update = true;
            }
        }

        if (!update)
        {
            break;
        }

        if (round == n)
        {
            cout << -1 << "\n";
            return;
        }
    }

    using P = pair<ll, int>;
    vector<ll> dist(n + 1);
    for (int source = 1; source <= n; source++)
    {
        fill(dist.begin(), dist.end(), INF);
        priority_queue<P, vector<P>, greater<P>> heap;
        heap.push({0, source});
        dist[source] = 0;

        while (!heap.empty())
        {
            auto [curdis, u] = heap.top();
            heap.pop();

            if (curdis != dist[u])
                continue;

            for (auto [v, w] : graph[u])
            {
                int newweight = h[u] + w - h[v];
                if (dist[v] > curdis + newweight)
                {
                    dist[v] = curdis + newweight;
                    heap.push({dist[v], v});
                }
            }
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INF)
            {
                ans += 1000000000LL;
            }else{
                ans += 1LL * i * dist[i];
            }
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}