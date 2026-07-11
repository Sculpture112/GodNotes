#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1);

        vector<int> distance(n + 1, INF);
        vector<bool> visited(n + 1, false);
        distance[k] = 0;

        for (auto edges : times)
        {
            graph[edges[0]].push_back({edges[2], edges[1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (visited[u])
            {
                continue;
            }
            visited[u] = true;
            for (auto [w, v] : graph[u])
            {

                if (!visited[v] && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                    pq.push({distance[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (distance[i] == -1)
            {
                return -1;
            }
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};