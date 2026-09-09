#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 1005;
int n, m;

int degree[1005];
int p[1005];
int findroot(int x)
{
    if (p[x] == x)
        return x;
    return findroot(p[x]);
}

void unite(int x,int y){
    int fx = findroot(x);
    int fy = findroot(y);

    if(fx!=fy){
        p[x] = y;
    }
    return;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        unite(u, v);
        degree[u]++, degree[v]++;
    }

    int root = findroot(1);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if(findroot(i) != root || degree[i] %2 != 0){
            ok = false;
            break;
        }
    }

    cout << ok ? 1 : 0;
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n && n != 0)
    {
        cin >> m;
        solve();
    }

    return 0;
}