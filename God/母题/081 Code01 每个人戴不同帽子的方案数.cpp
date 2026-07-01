#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberWays(vector<vector<int>> &arr)
    {
        int m = 0;
        for(auto& person : arr){
            for(int hat : person){
                m = max(m, hat);
            }
        }

        int n = arr.size();

        vector<int> hats(m + 1, 0);
        
    }
};