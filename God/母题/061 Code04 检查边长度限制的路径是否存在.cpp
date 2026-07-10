#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        int n = edgeList.size();
        int m = queries.size();

        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        vector<vector<int>> queries(m + 1, 4);
        for (int i = 0; i < m;i++){
            queries[i][0] = queries
        }
    }
};