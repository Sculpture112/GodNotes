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
        if(n!=0)
            m = matrix[0].size();

        int a = 0, b = 0, c = 0, d = 0;
        int maxsum = INT_MIN;

        for (int a = 0; a < n;a++){
            for (int c = a; c < n;c++){
                vector<int> nums(m, 0);
                int pre = 0;
                for (int j = 0;j<m;j++){
                    nums[j] += matrix[c][j];

                }
            }
        }
    }
};