#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int free(vector<int>& prices){
        int ans = 0;
        for (int i = 1; i < prices.size();i++){
            ans += (0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (k == 0 || n == 0)
        {
            return 0;
        }
        if (k >= n / 2)
        {
            return free(prices);
        }

        vector<int> dp(n, 0);
        for (int i = 0; i < k;i++){
            int best = dp[0] - prices[0];
            for (int j = 1; j < n;j++){
                int tmp = dp[j];
                dp[j] = max(dp[j - 1], best + prices[i]);
                best = max(best, tmp - prices[i]);
            }
        }
        return dp[n - 1];
    }
};
