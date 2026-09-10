#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> stack;
    vector<int> deepth(n + 1);
    vector<int> order;
    vector<int> parent(n + 1);
    ll rootsum = 0;

    parent[1] = -1;
    stack.push_back(1);

    while (!stack.empty())
    {
        int u = stack.front();
        stack.pop_back();
        order.push_back(u);
        rootsum += deepth[u];
        for (int v : graph[u])
        {
            if (v == parent[u])
                continue;
            deepth[v] = deepth[u] + 1;
            parent[v] = u;
            stack.push_back(v);
        }
    }

    vector<int> size(n + 1, 1);
    for (int i = n - 1; i > 0; i--)
    {
        int v = order[i];
        size[parent[v]] += size[v];
    }

    vector<ll> distance(n + 1);
    distance[1] = rootsum;
    for (int i = 1; i < n; i++)
    {
        int u = order[i];
        int p = parent[u];
        distance[u] = distance[p] + n - 1LL * 2 * size[u];
    }

    int node = 1;
    ll ans = INF;
    for (int i = 1; i <= n; i++)
    {
        if (distance[i] < ans)
        {
            node = i;
            ans = distance[i];
        }
    }

    cout << node << " " << ans;
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