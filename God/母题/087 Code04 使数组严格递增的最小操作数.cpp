#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        int m = 1;
        for (int i = 1; i < arr2.size(); i++)
        {
            if (arr2[i] != arr2[m - 1])
            {
                arr2[m++] = arr2[i];
            }
        }

        int n = arr1.size();
        vector<int> dp(n, -1);
        int ans = f1(arr1, arr2, n, m, dp, 0);
        return ans == INT_MAX ? -1 : ans;
    }
    int f1(vector<int>& arr1,vector<int>& arr2,int n,int m,vector<int>& dp,int i){
        if(i == n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];

        int find = bs(arr2, m, arr1[i]);
        int pre = arr1[i - 1];
        int ans = INT_MAX;
        for (int j = i, k = 0, next; j <= n; j++)
        {
            if(j == n){
                return 0;
            }
            else{
                if(pre<arr1[i]){
                    next = f1(arr1, arr2, n, m, dp, j + 1);
                    if(next != INT_MAX){
                        ans = min(ans, k + next);
                    }
                }


                if(find != -1 && find < m){
                    pre = arr2[find++];
                }
                else{
                    break;
                }
            }
        }
        dp[i] = ans;
        return ans;
    }
    int bs(vector<int>& arr,int len,int num)
    {
        int l = 0, r = len - 1, m;
        int ans = -1;
        while (l <= r)
        {
            m = l + ((r - l) << 1);
            if(arr[m]>num){
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
