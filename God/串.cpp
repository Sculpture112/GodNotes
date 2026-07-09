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
            int group = i % g;
            int r = (s[i] - '0') % 9;
            cnt[group][r]++;
            sz[group]++;
        }

        vector<vector<int>> cost(g, vector<int>(9, 0));
        for (int i = 0; i < g;i++){
            for (int j = 0; j < 9;j++){
                cost[i][j] = sz[i] - cnt[i][j];
            }
        }

        const int INF = 1e9;

        vector<int> dp(9, INF);
        dp[0] = 0;
        for (int i = 0; i < g; i++) {
            vector<int> ndp(9, INF);
            for (int oldSum = 0; oldSum < 9; oldSum++) {
                if(dp[oldSum] == INF) continue;
                for (int r = 0; r < 9;r++){
                    int newSum = (oldSum + r) % 9;
                    ndp[newSum] = min(ndp[newSum], dp[oldSum] + cost[i][r]);
                }
            }
        }

        int ans = INF;
        for (int sum = 0; sum < 9;sum++){
            int windowsum = sum * (9 / g) % 9;
            if(windowsum == 0){
                ans = min(ans, dp[sum]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}