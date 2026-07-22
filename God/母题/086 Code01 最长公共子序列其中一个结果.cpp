#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 5001;
int dp[MAXN][MAXN];
char ans[MAXN];
int n, m, k;
string s1, s2;

void filldp()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

void lcs()
{
    k = dp[n][m];
    for (int len = k, i = n, j = m; len > 0;)
    {
        if (s1[i-1] == s2[j-1])
        {
            ans[--len] = s1[i-1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    filldp();
    lcs();
    if (k == 0)
    {
        cout << -1;
    }
    else
        cout.write(ans, k), cout << "\n";

    return 0;
}
