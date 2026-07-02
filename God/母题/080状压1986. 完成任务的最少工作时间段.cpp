#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int n = tasks.size();

        vector<int> dp(1 << n, -1);
        return f(tasks, sessionTime, 0, n, dp, (1 << n) - 1, 0);
    }
    int f(vector<int> &tasks, int limit, int cur, int n, vector<int> &dp, int status, int count)
    {
        if (status == 0)
        {
            return count;
        }

        if (dp[status] != -1)
        {
            return dp[status];
        }

        for (int i = 0; i < n; i++)
        {
            if ((status & (1 << i)) != 0 && cur + tasks[i] <= limit)
            {
                if (cur + tasks[i] == limit)
                {
                    count += f(tasks, limit, 0, n, dp, status ^ (1 << i), count + 1);
                }
                else
                {
                    count += f(tasks, limit, cur + tasks[i], n, dp, status ^ (1 << i), count);
                }
            }
        }
        return count;
    }
};