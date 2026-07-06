#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp1 = 0;
        int best = -prices[0];
        int ans = 0;
        int mn = prices[0];

        for (int i = 0; i < prices.size(); i++)
        {
            mn = min(mn,prices[i]);
            dp1 = max(dp1, prices[i] - mn);
            best = max(best, dp1 - prices[i]);
            ans = max(ans, best + prices[i]);
        }
        return ans;
    }
};
