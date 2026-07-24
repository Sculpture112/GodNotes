#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
vector<int> a, b, c;
vector<vector<int>> dp;
vector<vector<string>> path;
#define all(x) (x).begin(), (x).end()

int m, v, n;
void solve()
{
    string p2;
    for (int i = 1; i <= n; i++)
    {
        for (int x = m; x >= a[i]; x--)
        {
            for (int y = v; y >= b[i]; y--)
            {
                int value = dp[x - a[i]][y - b[i]] + c[i];
                if (path[x - a[i]][y - b[i]].empty())
                {
                    p2 = to_string(i);
                }
                else
                {
                    p2 = path[x - a[i]][y - b[i]] + " " + to_string(i);
                }
                if (dp[x][y] < value)
                {
                    dp[x][y] = value;
                    path[x][y] = p2;
                }
                else if (dp[x][y] == value && p2 < path[x][y])
                {
                    path[x][y] = p2;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> v >> n;
    a.assign(n + 1, 0);
    b.assign(n + 1, 0);
    c.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp.assign(m + 1, vector<int>(v + 1, 0));
    path.assign(m + 1, vector<string>(v + 1));

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}
