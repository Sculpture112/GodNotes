#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
class Solution
{
public:
    int numPermsDISequence(string s)
    {
        int n = s.size()+1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int less = 0;less<=n;less++){
            dp[n][less] = 1;
        }

        for (int i = n - 1; i >=0 ;i--){
            if(i == 0||s[i-1]){

            }
        }
    }
};