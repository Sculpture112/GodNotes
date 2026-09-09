#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int n, m;
void solve() {
    int a, b, c;
    vector<pair<int,int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].first = b,graph[a].second = c;
    }

    int ans = 0;
    queue<int> q;
    
    while(q.empty()){

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while(n!=0 || m != 0){
        solve();
    }

    return 0;
}