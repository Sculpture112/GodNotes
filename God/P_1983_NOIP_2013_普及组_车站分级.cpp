#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 1005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bitset<MAXN>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;

        vector<int> stops(s);
        vector<bool> isstop(n + 1, false);
        bitset<MAXN> stopbits;

        for (int j = 0; j < s; j++)
        {
            cin >> stops[j];
            isstop[stops[j]] = true;
            stopbits.set(stops[j]);
        }

        int left = stops.front();
        int right = stops.back();

        for (int station = left; station <= right;station++){
            if(!isstop[station]){
                adj[station] |= stopbits;
            }
        }
    }

    vector<int> indegree(n + 1);

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(adj[i][j])
                indegree[j]++;
        }
    }

    queue<int> q;

    vector<int> dp(n + 1, 1);

    for (int i = 1; i <= n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int ans = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        ans = max(ans, dp[u]);
        for (int v = 1; v <= n;v++){
            if(adj[u][v]){
                dp[v] = max(dp[v], dp[u] + 1);
                if(--indegree[v] == 0){
                    q.push(v);
                }
            }
        }
    }
    cout << ans;

    return 0;
}