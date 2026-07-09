#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] !=0){
                    sz[grid[i][j]]++;
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {

            
        }
    }
    void dfs(int n, int m, vector<vector<int>> &grid, int id, int i, int j)
    {
        if (i < 0 || i == n || j < 0 || j == m)
            return;

        grid[i][j] == id;
        dfs(n, m, grid, id, i + 1, j);
        dfs(n, m, grid, id, i, j - 1);
        dfs(n, m, grid, id, i - 1, j);
        dfs(n, m, grid, id, i, j + 1);
    }
};
