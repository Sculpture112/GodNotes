#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int n, m;
int ans = 0;
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
void dfs(int x,int y)
{
    for()
}
void solve()
{
    cin >> n >> m;
    vector<string> graph;
    vector<vector<bool>> used(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'W' && !used[i][j])
            {
                dfs();
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