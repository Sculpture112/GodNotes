#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int id = 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    dfs(n, m, grid, id++, i, j);
            }
        }

        vector<int> sz(id, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    sz[grid[i][j]]++;
                    ans = max(ans, sz[grid[i][j]]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    vector<bool> visited(id, false);
                    int up, down, right, left, merge = 0;
                    up = i > 0 ? grid[i - 1][j] : 0;
                    down = i < n - 1 ? grid[i + 1][j] : 0;
                    right = j < m - 1 ? grid[i][j + 1] : 0;
                    left = j > 0 ? grid[i][j - 1] : 0;

                    merge = sz[up] + 1;

                    visited[up] = true;
                    if (!visited[down])
                    {
                        merge += sz[down];
                        visited[down] = true;
                    }
                    if (!visited[right])
                    {
                        merge += sz[right];
                        visited[right] = true;
                    }
                    if (!visited[left])
                    {
                        merge += sz[left];
                        visited[left] = true;
                    }
                    ans = max(ans, merge);
                }
            }
        }
        return ans;
    }
    void dfs(int n, int m, vector<vector<int>> &grid, int id, int i, int j)
    {
        if (i < 0 || i == n || j < 0 || j == m||grid[i][j] != 1)
            return;

        grid[i][j] = id;
        dfs(n, m, grid, id, i + 1, j);
        dfs(n, m, grid, id, i, j - 1);
        dfs(n, m, grid, id, i - 1, j);
        dfs(n, m, grid, id, i, j + 1);
    }
};
