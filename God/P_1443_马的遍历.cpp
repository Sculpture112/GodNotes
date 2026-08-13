#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int n, m;
int arr[401][401];
int step = 0;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
void dfs(int x, int y)
{
    if (x > n || y > m || x < 0 || y < 0)
        return;
    arr[x][y] = step;
    for (int i = 0; i < 8; i++) {
        dfs(dx[i] + x)(dy[i] + y);
    }
}

void solve()
{
    int x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = -1;
        }
    }
    x--, y--;
    dfs(x, y);
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