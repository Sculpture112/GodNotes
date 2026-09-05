#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 1 << 62;
const double DINF = 1e100;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    cin >> n >> m;
    int sx, sy;
    vector<string> graph(n);
    vector<pair<int, int>> patrol[26];
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
        for (int j = 0; j < m; j++)
        {
            char ch = graph[i][j];
            if (ch == '@')
            {
                sx = i, sy = j;
            }
            else if (ch <= 'Z' && ch >= 'A')
            {
                patrol[ch - 'A'].push_back({i, j});
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[sx][sy] = 0;
    q.push({sx, sy});

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (graph[x][y] == '=')
        {
            cout << dist[x][y];
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == '#')
            {
                continue;
            }

            char ch = graph[nx][ny];
            if (ch <= 'Z' && ch >= 'A')
            {
                auto &v = patrol[ch - 'A'];
                if (nx == v[0].first && ny == v[0].second)
                {
                    nx = v[1].first;
                    ny = v[1].second;
                }
                else
                {
                    nx = v[0].first;
                    ny = v[0].second;
                }
            }

            if (dist[nx][ny] == -1)
            {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}