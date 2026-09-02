#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> cows(k);
    for(int& num:cows)
        cin >> num;

    vector<vector<int>> graph(n+1);
    for (int i = 0,u,v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> reached(n + 1);
    for(int num:cows){
        vector<bool> isivisted(n + 1, false);
        queue<int> q;
        q.push(num);
        isivisted[num] = true;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            reached[num]++;
            for(int v : graph[num]){
                if(!isivisted[v]){
                    q.push(v);
                    isivisted[v] = true;
                }
            }
        }
    }
    int ans = 0;
    for(int num :reached){
        if(num == k){
            ans++;
        }
    }
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