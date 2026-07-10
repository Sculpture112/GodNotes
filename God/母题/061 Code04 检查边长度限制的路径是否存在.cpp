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

        vector<vector<int>> questions(m + 1, vector<int>(4,0));
        for (int i = 0; i < m;i++){
            questions[i][0] = queries[i][0];
            questions[i][1] = queries[i][1];
            questions[i][2] = queries[i][2];
            questions[i][3] = i;
        }
        sort(questions.begin(), questions.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        int father[n + 1];
        for (int i = 1; i <= n; i++)
        {
            father[i] = i;
        }


    }
    int find (int i){
        if(i != father[i]){
            father[i] = find(father[i]);
        }
        return father[i];
    }
    bool unite(int x,int y){
        
    }
};