#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()


void bfs(){

}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> graph;
    int sx, sy;
    
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
        for (int j = 0; j < m; j++) {
            if(graph[i][j] =='@'){
                sx = i, sy = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;j++){
            bfs();
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