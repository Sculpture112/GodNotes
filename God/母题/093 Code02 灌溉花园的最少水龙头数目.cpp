#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> right(n + 1, 0);
        for (int i = 0, start; i <= n; i++)
        {
            start = max(0, i - ranges[i]);
            right[start] = max(right[start], i + ranges[i]);
        }

        int ans = 0;
        int cur = 0;
        int nxt = 0;

        for (int i = 0; i < n; i++)
        {
            nxt = max(nxt, right[i]);
            if (cur == i)
            {
                if (nxt > i)
                {
                    ans++;
                    cur = nxt;
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
