#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 1005;
int p[MAXN];
int sz[MAXN];
vector<vector<int>> order;
int findp(int x)
{
    if (p[x] == x)
    {
        return x;
    }

    return findp(p[x]);
}

void unite(int x, int y)
{
    int fx = findp(x);
    int fy = findp(y);

    if (fx != fy)
    {
        if (fx < fy)
        {
            p[fx] = fy;
            sz[fy] = lcm(sz[fx], sz[fy]);
        }
        else
        {
            p[fy] = fx;
            sz[fx] = lcm(sz[fx], sz[fy]);
        }
        // order[fy].push_back(sz[fy]);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        sz[i] = i;
    }

    order.reserve(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (p[i] == i)
        {
            cout << sz[i] << "\n";
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     int p = findp(i);
    //     cout << *order[p].end();
    // }
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