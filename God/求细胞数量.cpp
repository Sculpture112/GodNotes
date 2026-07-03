#include <bits/stdc++.h>
using namespace std;
int n, m;
int cell = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y, vector<vector<int>> &grid)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (grid[nx][ny] == 0)
            continue;

        grid[nx][ny] = 0;
        dfs(nx, ny, grid);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
            {
                cell++;
                grid[i][j] = 0;
                dfs(i, j, grid);
            }
        }
    }
    cout << cell;

    return 0;
}