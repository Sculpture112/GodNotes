#include <bits/stdc++.h>
using namespace std;
int m, n;
string dp[1005];
string add(string a, string b)
{
    string ans;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i--] - '0';
        }
        if (j >= 0)
            sum += b[j--] - '0';
        ans.push_back(sum % 10 + '0');
        carry =sum / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    dp[m] = '1';
    dp[m + 1] = '1';

    for (int i = m + 2; i <= n; i++)
    {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }
    cout << dp[n];

    return 0;
}