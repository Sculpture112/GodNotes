#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTransfers(vector<vector<int>> &transactions)
    {
    }
    vector<int> dept(vector<vector<int>> &transaction)
    {
        vector<int> help(13, 0);
        for (auto &tran : transaction)
        {
            help[tran[0]] -= tran[2];
            help[tran[1]] += tran[2];
        }

        vector<int> help;
        for()
    }
};