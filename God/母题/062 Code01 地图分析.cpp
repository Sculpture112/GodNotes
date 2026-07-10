#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> queue(n * m);
        int l = 0, r = 0;
        int seas = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    visited[i][j] = true;
                    queue[r++] = {i, j};
                }
                else
                {
                    seas++;
                }
            }
        }

        int level = 0;
        while (l < r)
        {
            level++;
            auto [i, j] = queue[l++];
            int size = r - l;
            for (int k = 0; k < size; k++)
            {
                for (int i = 0; i < 4; i++)
                {
                    
                }
            }
        }
    }
};