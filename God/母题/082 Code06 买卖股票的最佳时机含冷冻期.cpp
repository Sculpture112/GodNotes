#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int done1 = max(0, prices[1] - prices[0]);
        int don2 = 0;
        int prepare = max(-prices[0], -prices[1]);

        for (int i = 2; i < prices.size();i++){
            int curdone = max(done1, prepare + prices[i]);
            prepare = max(prepare, don2 - prices[i]);
            don2 = done1;
            done1 = curdone;
        }

        return done1;
    }
};
