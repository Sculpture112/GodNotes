#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5001;
const int MAXM = 200005;
int father[MAXN];

struct Edge
{
    int u, v, w;
};
Edge edges[MAXM];

int find(int i)
{

    if (i != father[i])
    {
        father[i] = find(father[i]);
    }
    return father[i];
}
bool unite(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        father[fx] = fy;
        return true;
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges + m, [](const Edge &a, const Edge &b)
         { return a.w < b.w; });

    int ans = 0;
    int edgecnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (unite(edges[i].u, edges[i].v))
        {
            edgecnt++;
            ans += edges[i].w;
        }
    }

    if (edgecnt == n - 1)
    {
        cout << ans;
    }
    else
    {
        cout << "orz";
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
