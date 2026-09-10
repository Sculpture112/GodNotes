#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int ans = 0;
vector<bool> vis(25,false);
void dfs(int u,int t,vector<vector<int>>& graph){
    if(u == t){
        ans++;
        return;
    }

    for(int v:graph[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v, t, graph);
            vis[v] = false;
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int t;
    cin >> t;

    vis[1] = true;
    dfs(1, t, graph);
    cout << ans;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}