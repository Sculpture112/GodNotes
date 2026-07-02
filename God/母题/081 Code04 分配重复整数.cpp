#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canDistribute(vector<int> &nums, vector<int> &quantity)
    {
        sort(nums.begin(), nums.end());
        vector<int> cnt;

        for (int i = 0; i < nums.size();i++){
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[i]){
                j++;
            }
            cnt.push_back(j - i);
        }

        int n = cnt.size();
        int m = quantity.size();
        vector<int> sum(1 << m, 0);

        for (int i = 0; i < m;i++){
            int h = 1 << i;
            for (int j = 0; j < h;j++){
                sum[h | j] = sum[j] + quantity[i];
            }
        }

        vector<vector<int>> dp(1 << m, vector<int>(n, -1));

        return 
    }

    bool f(vector<int>& cnt,vector<int>& sum,int status,int index,int n,int m,vector<vector<int>>& dp)
    {
        if(status == 0){
            return true;
        }

        if(index == n){
            return false;
        }

        if(dp[status][index] !=0 ){
            return dp[status][index] == 1;
        }

        int k = cnt[index];
        bool ans = false;

        for()
    }
};