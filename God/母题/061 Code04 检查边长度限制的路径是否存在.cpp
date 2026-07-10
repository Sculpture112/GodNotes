#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> father;
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        int b = edgeList.size();
        int m = queries.size();

        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        vector<vector<int>> questions(m, vector<int>(4,0));
        for (int i = 0; i < m;i++){
            questions[i][0] = queries[i][0];
            questions[i][1] = queries[i][1];
            questions[i][2] = queries[i][2];
            questions[i][3] = i;
        }
        sort(questions.begin(), questions.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        father.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
        }

        vector<bool> ans(m);
        for (int i = 0, j = 0; i < b; i++)
        {
            for (; j < m&& edgeList[j][2]<questions[i][2];j++){
                unite(edgeList[j][0], edgeList[j][1]);
            }
            ans[questions[i][3]] = Issamset(questions[i][0], questions[i][1]);
        }
        return ans;
    }
    int find (int i){
        if(i != father[i]){
            father[i] = find(father[i]);
        }
        return father[i];
    }
    bool unite(int x,int y){
        if(find(x) != find(y)){
            father[find(x)] = find(y);
            return true;
        }
        return false;
    }
    bool Issamset(int x,int y){
        return find(x) == find(y);
    }
};