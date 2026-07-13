#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

const int MOD = 1e9 + 7;
#define all(x) (x).begin(), (x).end()

class Solution
{
public:

    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            int window = 1;
            for (int j = 1; j <= k;j++){
                if(j-i+1<=0){
                    window = (window + dp[i - 1][j]) % MOD;
                }
                else{
                    window = (window + dp[i - 1][j] - dp[i - 1][j - i] + MOD) % MOD;
                }
                dp[i][j] = window;
            }
        }
        return dp[n][k];
    }
};
