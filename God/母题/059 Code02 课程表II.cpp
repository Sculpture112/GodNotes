#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        vector<int> queue(numCourses);
        int l = 0, r = 0;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                queue[r++] = i;
            }
        }

        int cnt = 0;
        while (l < r)
        {
            int cur = queue[l++];
            cnt++;
            for (int next : graph[cur])
            {
                if (--indegree[next] == 0)
                {
                    queue[r++] = next;
                }
            }
        }
        return cnt == numCourses ? queue : vector<int>();
    }
};