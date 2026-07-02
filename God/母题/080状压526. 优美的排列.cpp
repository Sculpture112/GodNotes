#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countArrangement(int n)
    {
        vector<int> dp(1 << n, 0);
    }
    int f(int status, int index, vector<int> &dp, int n)
    {
        if (status == 0)
        {
            return 1;
        }

        if (index == n)
        {
            return 0;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((status & (1 << i)) != 0 && ((i % index == 0) || (index % i == 0)))
            {
                ans += f(status ^ (1 << i), index + 1, dp, n);
            }
        }
        dp[status] = ans;
        return ans;
    }
};