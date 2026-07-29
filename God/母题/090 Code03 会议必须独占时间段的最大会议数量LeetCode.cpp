#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &meeting)
    {
        sort(meeting.begin(), meeting.end(), [](const auto &a, const auto &b)
             { return a[1] < b[1]; });

        int n = meeting.size();
        int ans = 0;
        for (int i = 0, cur = -50001; i < n; i++)
        {
            if(meeting[i][0]>=cur){
                cur = meeting[i][1];
                ans++;
            }
        }
        return n - ans;
    }
};