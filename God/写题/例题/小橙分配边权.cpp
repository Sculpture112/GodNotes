#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    cin >> n >> m;

    int s = -1;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0 && s == -1)   
        {
            s = i;
        }
    }

    vector<pair<int, int>> edges(m);
    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (s == -1)
    {
        cout << -1 << "\n";
        return;
    }

    queue<int> q;
    vector<bool> visited(n + 1, false);

    q.push(s);
    visited[s] = true;
    int touched = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        touched++;
        for (int u : graph[cur])
        {
            if (!visited[u] && a[u] >= a[cur])
            {
                q.push(u);
                visited[u] = true;
            }
        }
    }
    if (touched != n)
    {
        cout << -1 << "\n";
        return;
    }

    for (auto [u, v] : edges)
    {
        cout << abs(a[u] - a[v]) << "\n";
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