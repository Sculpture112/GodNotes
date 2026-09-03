#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<string> maze(n);
        int sx = 0, sy = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> maze[i];
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == 'S')
                {
                    sx = i, sy = j;
                }
            }
        }

        int total = n * m;
        vector<bool> visited(total, false);
        vector<int> orginx(total), orginy(total);

        queue<pair<int, int>> q;
        q.push({sx, sy});
        int startid = sx * m + sy;
        visited[startid] = true;
        orginx[startid] = sx;
        orginy[startid] = sy;

        auto mod = [](int x, int p)
        {
            return (x % p + p) % p;
        };

        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        bool canEcaspe = false;
        while (!q.empty() && !canEcaspe)
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                int rx = mod(nx, n);
                int ry = mod(ny, m);

                if (maze[rx][ry] == '#')
                    continue;

                int id = rx * m + ry;
                if (!visited[id])
                {
                    q.push({nx, ny});
                    visited[id] = true;
                    orginx[id] = nx;
                    orginy[id] = ny;
                }
                else if (orginx[id] != nx || orginy[id] != ny)
                {
                    canEcaspe = true;
                    break;
                }
            }
        }

        cout << (canEcaspe ? "Yes\n" : "No\n");
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