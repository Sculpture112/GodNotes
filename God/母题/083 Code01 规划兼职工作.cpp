#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();

        vector<array<int, 3>> jobs(n);
        for (int i = 0; i < n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end(), [](const auto &a, const auto &b)
             { return a[1] < b[1]; });
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++)
        {
            int cur = jobs[i][2];
            int pre = find(jobs, i - 1, jobs[i][0]);
            if (pre != -1)
            {
                cur += dp[pre];
            }
            dp[i] = max(dp[i - 1], cur);
        }
        return dp[n - 1];
    }
    int find(vector<array<int,3>> &jobs, int r, int start)
    {
        int ans = -1;
        int l = 0;
        while (l <= r)
        {
            int m = (l - r) / 2 + r / 2;

            if (jobs[m][1] < start)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
};