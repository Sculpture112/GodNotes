#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    unordered_map<int, int> dp;
    int minDays(int n)
    {
        if (n <= 1)
            return n;
        if (dp.count(n))
        {
            return dp[n];
        }

        int ans = min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
        dp[n] = ans;
        return ans;
    }
};