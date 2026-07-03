#include <bits/stdc++.h>
using namespace std;
int m, n;
bool visited[1001];
int ans = 0;
int dfs(int x)
{
    if (x == n)
    {
        return 1;
    }

    if (x - n >= 3)
    {
        return 0;
    }

    if (visited[x] = false)
    {
        return 0;
    }

    for (int i = -2; i <= 2; i++)
    {
        if (i == 0)
            continue;
        
        ans += dfs(i);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    cout<<dfs(m);

    return 0;
}