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
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    vector<int> dp(n + 1, 0);

    for (int u = 1; u <= n; u++)
    {
        if(dp[u] == 0)continue;
        for(auto[v,w]:graph[u]){
            dp[v] = max(dp[v], dp[u] + 1);
        }
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