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
        if(seas == 0||seas == n*m){
            return -1;
        }

        int level = 0;
        while (l < r)
        {
            level++;
            int size = r - l;
            for (int k = 0; k < size; k++)
            {
                auto [x, y] = queue[l++];
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx == n || ny < 0 || ny == m || !visited[nx][ny])
                    {
                        continue;
                    }
                    visited[nx][ny] = true;
                    queue[r++] = {nx, ny};
                }
            }
        }
        return level - 1;
    }
};