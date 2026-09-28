#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL << 62;
const double DINF = 1e100;

#define all(x) (x).begin(), (x).end()
const int MAXN = 1005;

void solve()
{
    int n, m;
    cin >> n >> m;

    int s;
    cin >> s;

    vector<bitset<MAXN>> adj(n+1);

    for (int i = 0; i < m; i++)
    {
        vector<int> stop(s);
        vector<bool> isstop(s+1, false);
        bitset<MAXN> bitstop;
        for (int j = 0; j < s; i++)
        {
            cin >> stop[j];
            isstop[stop[j]] = true;
            bitstop.set(stop[j]);
        }

        int left = stop.front();
        int right = stop.back();

        for (int station = left; station <= right;station++){
            if(!isstop[station]){
                adj[station] |= bitstop;
            }
        }
    }

    vector<int> indegree(n+1);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(adj[i][j]==1){
                indegree[j]++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> dp(n + 1,1);
    int ans = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans = max(ans, dp[u]);

        for (int v = 1; v <= n;v++){
            if(adj[u][v]){
                dp[v] = max(dp[v], dp[u] + 1);
                if(--indegree[v]==0){
                    q.push(v);
                }
            }
        }
    }

    cout << ans;
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