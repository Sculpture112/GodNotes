#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> graph(n, vector<int>(m));
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < t;i++){
        int x, y;
        cin >> x >> y;
        graph[x][y] = -1;
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