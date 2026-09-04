#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int graph[6][6];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, m, t;
int ans = 0;
int a, b, c, d;
int visited[6][6];
void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }
    if (x == c && y == d)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if ()
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            visited[nx][ny] = true;
            dfs(nx, ny);
            visited[nx][ny] = false;
        }
    }
}
void solve()
{
    cin >> n >> m >> t;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = -1;
    }
    visited[a][b] = true;
    dfs(a, b);
    cout << ans;
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