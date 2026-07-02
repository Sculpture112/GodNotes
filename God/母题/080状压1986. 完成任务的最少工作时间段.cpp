#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int n = tasks.size();
        int size = 1 << n;

        vector<int> sum(size, 0);

        for (int status = 1; status < size; status++)
        {
            int rightone = status & -status;
            int i = __builtin_ctz(rightone);
            sum[status] = sum[status ^ rightone] + tasks[i];
        }

        const int INF = 0x3f3f3f3f;
        vector<int> dp(size, INF);

        dp[0] = 0;

        for (int statu = 1; statu < size; statu++)
        {
            for (int sub = statu; sub > 0; sub = (sub - 1) & statu)
            {
                if (sum[sub] <= sessionTime)
                {
                    dp[statu] = min(dp[statu], dp[statu ^ sub] + 1);
                }
            }
        }
        
        
        return dp[size-1];
    }
};