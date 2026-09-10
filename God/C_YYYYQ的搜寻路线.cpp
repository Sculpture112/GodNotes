#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int ans = 0;
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

    vector<bool> vis(n + 1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==t)
        {
            ans++;
            continue;
        }
        for(int v:graph[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}