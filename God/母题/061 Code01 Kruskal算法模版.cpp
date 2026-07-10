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
bool unite(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
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

    int edges[MAXM][3];
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    sort(edges, edges + m, [](const auto &a, const auto &b)
         { return a[2] < b[2]; });

    int ans = 0;
    int edgecnt = 0;
    for (int i = 0; i < m;i++){
        if(unite(edges[i][0],edges[i][1])){
            edgecnt++;
            ans += edges[i][2];
        }
    }

    if(edgecnt == n-1){
        cout << ans;
    }
    else{
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
