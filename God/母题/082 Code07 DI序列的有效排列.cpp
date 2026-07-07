#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
class Solution
{
public:
    int numPermsDISequence(string s)
    {
        int n = s.size() + 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int less = 0; less <= n; less++)
        {
            dp[n][less] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == 0 || s[i - 1] == 'D')
            {
                // dp[i][less] = dp[i+1][0] + dp[i+1][1] ... dp[i+1][less-1]
                dp[i][1] = dp[i + 1][0];
                for (int less = 2; less <= n; less++)
                {
                    dp[i][less] = (dp[i][less - 1] + dp[i + 1][less - 1])%mod;
                }
            }
            else
            {
                // dp[i][less] = dp[i+1][less] + dp[i+1][less+1] + dp less +2 ... dp[i+1][n-i-1]
                dp[i][n - i - 1] = dp[i + 1][n - i - 1];
                for (int less = n - i - 2; less >= 0; less--)
                {
                    dp[i][less] = (dp[i][less + 1] + dp[i + 1][less]) % mod;
                }
            }
        }
        return dp[0][n];
    }
};