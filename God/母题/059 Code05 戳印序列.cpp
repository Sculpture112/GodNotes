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
                if (s[i + j] == s[j])
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

        vector<int> path(n-m+1);
        int cnt = 0;
        vector<bool> visited(n,false);
        while (l < r)
        {
            int cur = queue[l++];
            path.push_back(cur);
            cnt++;
            for (int nxt : graph[cur])
            {
                if(!visited[cur ])
            }
        }
    }
};
