#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5001;
const int MAXM = 20005;
int father[MAXN];

int find(int i)
{

    if (i != father[i])
    {
        father[i] = find(father[i]);
    }
    return father[i];
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n;i++){
        father[i] = i;
    }

    int edges[MAXM][3];
    for (int i = 0; i < m;i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    sort(edges,edges+m,[])
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
