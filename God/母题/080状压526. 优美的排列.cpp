#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countArrangement(int n)
    {
        vector<int> dp(1 << n, -1);
        return f((1 << n) - 1, 1, dp, n);
    }
    int f(int status, int index, vector<int> &dp, int n)
    {
        if (status == 0)
        {
            return 1;
        }

        if (index == n+1)
        {
            return 0;
        }

        if(dp[status] != -1){
            return dp[status];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((status & (1 << (i - 1))) != 0 && ((i % index == 0) || (index % i == 0)))
            {
                ans += f(status ^ (1 << (i-1)), index + 1, dp, n);
            }
        }
        dp[status] = ans;
        return ans;
    }
};