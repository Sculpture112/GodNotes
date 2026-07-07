#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int prepare = -prices[0] - fee;
        int done = 0;
        for (int i = 1; i < prices.size();i++){
            int lastdone = done;
            done = max(lastdone, prepare + prices[i]);
            prepare = max(prepare, lastdone - prices[i] - fee);
        }
        return done;
    }
};