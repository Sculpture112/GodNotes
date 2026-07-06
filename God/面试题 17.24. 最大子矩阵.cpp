#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> getMaxMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m;
        if (n != 0)
            m = matrix[0].size();

        int a = 0, b = 0, c = 0, d = 0;
        int maxsum = INT_MIN;

        vector<int> nums(m, 0);
        for (int up = 0; up < n; up++)
        {
            fill(nums.begin(), nums.end(), 0);
            for (int down = up; down < n; down++)
            {
                int pre = 0;
                for (int r = 0, l = 0, pre = INT_MIN; r < m; r++)
                {
                    nums[r] += matrix[down][r];

                    if (pre >= 0)
                    {
                        pre += nums[r];
                    }
                    else
                    {
                        pre = nums[r];
                        l = r;
                    }

                    if (pre > maxsum)
                    {
                        maxsum = pre;
                        a = up;
                        b = l;
                        c = down;
                        d = r;
                    }
                }
            }
        }
        return {a, b, c, d};
    }
};