#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTransfers(vector<vector<int>> &transactions)
    {
        vector<int> debt = debts(transactions);
        int n = debt.size();
        vector<int> dp((1 << n), -1);
        return n - f(debt, n, 0, (1 << n) - 1, dp);
    }
    vector<int> debts(vector<vector<int>> &transaction)
    {
        vector<int> help(13, 0);
        for (auto &tran : transaction)
        {
            help[tran[0]] -= tran[2];
            help[tran[1]] += tran[2];
        }

        vector<int> debt;
        for (int num : help)
        {
            if (num != 0)
            {
                debt.push_back(num);
            }
        }
        return debt;
    }
    int f(vector<int> &debt, int n, int sum, int s, vector<int> &dp)
    {
        if (dp[s] != -1)
        {
            return dp[s];
        }

        int ans = 0;
        if ((s & (s - 1)) != 0)
        {
            if(sum ==0){
                for (int i = 0; i < n;i++){
                    if((s & (1<<i)) != 0){
                        ans = f(debt, n, sum - debt[i], s ^ (1 << i), dp) + 1;
                        break;
                    }
                }
            }
            else{
                for (int i = 0; i < n;i++){
                    if((s & (1<<i)) != 0){
                        ans = max(ans,f(debt, n, sum - debt[i], s ^ (1 << i), dp));
                    }
                }
            }
        }
        dp[s] = ans;
        return ans;
    }
};