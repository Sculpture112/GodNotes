#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        int g = gcd(n, 9);

        vector<vector<int>> cnt(g, vector<int>(9, 0));
        vector<int> sz(g, 0);
        for (int i = 0; i < n;i++){
            int group = i % 9;
            int r = (s[i] - '0') % 9;
            cnt[group][r]++;
            sz[g]++;
        }

        vector<vector<int>> cost(g, vector<int>(9, 0));
        for (int i = 0; i < g;i++){
            for (int j = 0; j < 9;j++){
                cost[i][j] = sz[i] - cnt[i][j];
            }
        }

        
    }
    solve();

    return 0;
}