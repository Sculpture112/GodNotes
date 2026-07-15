#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int a, b;
int dp[11][11][2];

void build()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
}
int f(int num, int free, int pre, int len, int offset)
{
    if (len == 0)
        return 1;
    if (dp[len][pre][free] != -1)
    {
        return dp[len][pre][free];
    }

    int cur = num / offset % 10;

    int ans = 0;
    if (free == 0)
    {
        if (pre == 10)
        {

            ans += f(num, 1, 10, len - 1, offset / 10);
            for (int i = 1; i < cur; i++)
            {
                ans += f(num, 1, i, len - 1, offset / 10);
            }
            ans += f(num, 0, cur, len - 1, offset / 10);
        }
        else
        {
            for (int i = 0; i <= cur; i++)
            {
                if (i - pre >= 2 || pre - i >= 2)
                {
                    if (i < cur)
                    {
                        ans += f(num, 1, i, len - 1, offset / 10);
                    }
                    else if (i == cur)
                    {
                        ans += f(num, 0, cur, len - 1, offset / 10);
                    }
                }
            }
        }
    }
    else
    {
        if (pre == 10)
        {
            ans += f(num, 1, 10, len - 1, offset / 10);
            for (int i = 1; i <= 9; i++)
            {
                ans += f(num, 1, i, len - 1, offset / 10);
            }
        }
        else
        {
            for (int i = 0; i <= 9;i++){
                if(pre-i>=2||i-pre>=2){
                    ans += f(num, 1, i, len - 1, offset / 10);
                }
            }
        }
    }
    return dp[len][pre][free] = ans;
    ;
}
int cnt(int num)
{
    int len = 1;
    int offset = 1;
    int tmp = num / 10;
    while (tmp > 0)
    {
        tmp /= 10;
        offset *= 10;
        len++;
    }
    build();
    return f(num, 0, 10, len, offset);
}

void solve()
{
    cout << cnt(b) - cnt(a - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}
