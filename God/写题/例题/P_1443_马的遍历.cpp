#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));

    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
        int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};
        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m)
            {
                continue;
            }
            if (dist[nx][ny] != -1)
            {
                continue;
            }
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

        return 0;
}