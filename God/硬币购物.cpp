#include <bits/stdc++.h>
using namespace std;
int v[4], c[4];
int n, s;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; i++)
    {
        cin >> v[i];
    }

    cin >> n;

    while (n--)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> c[i];
        }
        cin >> s;
        // 前i个硬币，凑出块钱j的方法数
        vector<vector<int>> dp(4, vector<int>(s+1, 0));

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j <=s; j++)
            {
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; k < c[i];k++){
                    dp[i][j] += dp[i - 1][j - k * v[i]];
                }
            }
        }
        cout << dp[3][s] << "\n";
    }


    return 0;
}