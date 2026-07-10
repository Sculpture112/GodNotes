#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 100001;
vector<vector<int>> graph(MAXN);
int indegree[MAXN];
int cost[MAXN];
void solve()
{
    int n;
    cin >> n;
    while (n--)
    {

        int u;
        int w;
        cin >> u >> w;
        int x;
        cin >> x;
        cost[u] = w;
        while (x > 0)
        {

            graph[x].push_back(u);
            indegree[u]++;
            cin >> x;
        }
    }
    vector<pair<int, int>> queue;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[r++] = {cost[i], i};
        }
    }

    int ans = 0;
    while (l < r)
    {
        int sz = r - l;
        int mx = 0;
        for (int k = 0; k < sz;k++){
            auto [cost, i] = queue[l++];
            mx = max(mx, cost);
            for(int nxt : graph[i])
            {
                if(--indegree[nxt] == 0){
                    queue[l++] = {cost[nxt], nxt};
                }
            }
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