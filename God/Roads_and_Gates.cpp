#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = (1LL << 62);
void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, y;
    cin >> n >> m >> y;
    vector<vector<pair<int, int>>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }

    vector<ll> x(n);
    int h = n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        g[i].push_back({h, x[i] + y});
        g[h].push_back({i, x[i]});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    vector<ll> dist(n + 1, INF);
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v])
            continue;

        for (auto [to, cost] : g[v])
        {
            if (dist[to] > dist[v] + cost)
            {
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
    }

    for (int i = 1; i < n;i++){
        if(i>1){
            cout << " ";
        }
        cout << dist[i];
    }
        solve();

    return 0;
}