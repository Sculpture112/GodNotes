#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
struct Edge
{
    int to;
    int weight;
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    queue<int> q;
    vector<bool> inque(n + 1, false);
    q.push(1);
    inque[1] = true;
    vector<ll> dist(n + 1, LINF);
    vector<int> edgecnt(n + 1);
    bool ok = false;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        inque[cur] = false;

        for(auto [to,weight] : graph[cur]){
            ll newdis = dist[cur] + weight;
            if(newdis<dist[to]){
                dist[to] = newdis;
                edgecnt[to] = edgecnt[cur] + 1;
                if(edgecnt[to]>=n){
                    ok = true;
                }

                if(!inque[to]){
                    q.push(to);
                    inque[to] = true;
                }
            }
        }
    }

    cout << ok ? "NO\n" : "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}