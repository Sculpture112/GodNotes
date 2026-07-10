#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        int n = target.size();
        int m = stamp.size();
        string s = stamp;
        string t = target;
        vector<int> indegree(n - m + 1, m);
        vector<vector<int>> graph(n);
        // graph[x] ： x 可以解锁的stamp的位置
        vector<int> queue(n - m + 1, 0);
        int l = 0, r = 0;

        for (int i = 0; i <= n - m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (t[i + j] == s[j])
                {
                    if (--indegree[i] == 0)
                    {
                        queue[r++] = i;
                    }
                }
                else
                {
                    graph[i + j].push_back(i);
                }
            }
        }

        vector<int> path;
        vector<bool> visited(n,false);
        while (l < r)
        {
            int cur = queue[l++];
            path.push_back(cur);
            for (int i = 0; i < m;i++){
                if(!visited[cur + i]){
                    visited[cur + i] = true;
                    for(int nxt : graph[cur + i]){
                        if(--indegree[nxt] == 0){
                            queue[r++] = nxt;
                        }
                    }
                }
            }
        }
        if(path.size() != n-m+1){
            return vector<int>();
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
