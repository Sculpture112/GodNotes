#include <bits/stdc++.h>
using namespace std;
int m, n;
int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    dp[m] = 1;

    for (int i = m + 1; i<=n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];

    return 0;
}