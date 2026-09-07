#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

const int MAXN = 1005;
int cnt = 1;
int nxt[MAXN];
int head[MAXN];
int to[MAXN];

int indeg[MAXN], outdeg[MAXN];

int n, m;

void addedge(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
void solve()
{
    if (n == 0)
        return;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addedge(u, v);
        outdeg[u]++;
        indeg[v]++;
    }

    bool ans = true;

    for (int i = 1; i <= n; i++)
    {
        int diff = outdeg[i] - indeg[i];
        if (diff <= -1 || diff >= 1)
        {
            ans = false;
            break;
        }
    }

    cout << ans ? 1 : 0;
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n)
        solve();

    return 0;
}