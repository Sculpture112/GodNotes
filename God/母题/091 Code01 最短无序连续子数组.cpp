#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int right = -1;
        int maxvalue = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < maxvalue)
            {
                right = i;
            }
            maxvalue = max(maxvalue, nums[i]);
        }

        int left = n;
        int minvalue = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {

            if (nums[i] > minvalue)
            {
                left = i;
            }
            minvalue = min(minvalue, nums[i]);
        }
        return max(0, right - left + 1);
    }
};
