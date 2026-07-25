#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if(n==0)
            return 0;

        vector<int> end(n);
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            int find = bs(end, nums[i], len);
            if(find ==-1){
                end[len++] = nums[i];
            }
            else{
                end[find] = nums[i];
            }
        }
        return len;
    }
    int bs(vector<int>& end,int num,int len){
        int l = 0, r = len - 1, m;
        int ans = -1;
        
        while (l <= r)
        {
            m = l + (r - l) / 2;

            if(end[m]>=num){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return ans;
    }
};
