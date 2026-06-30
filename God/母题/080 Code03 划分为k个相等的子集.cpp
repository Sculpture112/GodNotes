#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        if (sum % k != 0)
        {
            return false;
        }

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> group(k, 0);
        return f(nums, group, n - 1, sum / k);
    }
    bool f(vector<int> &nums, vector<int> &group, int index, int limit)
    {
        if (index < 0)
        {
            return true;
        }
        int num = nums[index];
        int len = group.size();

        for (int i = 0; i < len; i++)
        {
            if (group[i] + num <= limit)
            {
                group[i] += num;
                if (f(nums, group, index - 1, limit))
                {
                    return true;
                }
                group[i] -= num;

                while (i + 1 < len && group[i] == group[i + 1])
                {
                    i++;
                }
            }
        }
        return false;
    }
};
