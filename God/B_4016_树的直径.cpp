#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int n;
pair<int, int> bfs(vector<vector<int>> &graph, int start)
{
    queue<int> q;
    q.push(start);
    vector<int> distance(n + 1, -1);
    distance[start] = 0;
    int farther = start;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (distance[cur] > distance[farther])
        {
            farther = cur;
        }
        for (auto v : graph[cur])
        {
            if (distance[v] == -1)
            {
                distance[v] = distance[cur] + 1;
                q.push(v);
            }
        }
    }

    return {farther, distance[farther]};
}
void solve()
{
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int x = bfs(graph, 1).first;
    int y = bfs(graph, x).second;
    cout << y << "\n";
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