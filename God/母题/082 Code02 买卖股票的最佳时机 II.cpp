#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        for (int i = 1; 1 < prices.size();i++){
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};