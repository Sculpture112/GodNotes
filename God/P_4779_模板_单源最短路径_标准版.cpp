#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
struct Edge{
    int v;
    int w;
};
void solve() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    using P = pair<ll, int>;

    priority_queue<P, vector<P>, greater<P>> heap;
    vector<ll> dist(n + 1, LINF);
    dist[s] = 0;
    heap.push({0, s});

    while(!heap.empty()){
        auto [cur, u] = heap.top();
        heap.pop();

        if(dist[u] != cur)continue;

        for(auto[v,w] : graph[u]){
            ll newdis = dist[u] + w;
            if(newdis<dist[v]){
                dist[v] = newdis;
                heap.push({newdis, v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
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