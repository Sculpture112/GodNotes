#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int INF = 0x3f3f3f3f;

int n;
int graph[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int f(int s,int i){
    if(s == (1<<n)-1)
}

int solve()
{
    return f(1,1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    solve();

    return 0;
}
