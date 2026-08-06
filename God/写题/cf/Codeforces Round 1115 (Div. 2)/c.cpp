#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> weight(n+1);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    vector<vector<int>> graph(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++){
            cin >> graph[i][j];
        }
    }
    vector<int> count(n + 1, -1);
    vector<int> srt;
    for (int i = n; i >= 1;i--){
        for (int j = 1; j <= m;j++){
            srt.push_back(graph[i][j]);
        }
        sort(srt.rbegin(), srt.rend());

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}