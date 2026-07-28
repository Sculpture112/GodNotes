#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        f(ans, 0, nums);
        return ans;
    }
    void f(vector<vector<int>>& ans,int i,vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(nums);
        }
        else{
            for (int j = i; j < nums.size();j++){
                swap(nums[i], nums[j]);
                f(ans, i + 1, nums);
                swap(nums[i], nums[j]);
            }
        }
    }
};