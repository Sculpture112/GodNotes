#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTransfers(vector<vector<int>> &transactions)
    {
        vector<int> debt = debts(transactions);
        int n = debt.size();
        
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
        for(int num : help){
            if(num!=0){
                debt.push_back(num);
            }
        }
        return debt;
    }
};