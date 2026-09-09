#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int n, m;
struct Edge
{
    int to;
    int weight;
};
void solve()
{
    int a, b, c;
    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    using P = pair<ll, int>;

    vector<ll> dist(n + 1, LINF);
    priority_queue<P, vector<P>, greater<P>> heap;
    dist[1] = 0;
    heap.push({0, 1});

    while (!heap.empty())
    {
        auto [cur, u] = heap.top();
        heap.pop();
        if (cur > dist[u])
            continue;
        if (u == n)
            break;

        for (auto [to, weight] : graph[u])
        {
            if (dist[to] > dist[u] + weight)
            {
                dist[to] = dist[u] + weight;
                heap.push({dist[to], to});
            }
        }
    }
    cout << dist[n] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        solve();
    }

    return 0;
}