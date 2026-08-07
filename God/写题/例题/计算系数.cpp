#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, k, n, m;
const int N = 1005;
const int MOD = 10007;
ll C[N][N];
void init()
{
    for (int i = 0; i <= 1000; i++)
    {
        C[i][i] = C[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}
ll power(ll a, ll b)
{
    ll ans = 1;
    a %= MOD;
    while (b)
    {
        if ((b & 1) != 0)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}
ll solve()
{
    ll ans = C[k][n];
    ans = ans * power(a, n) % MOD;
    ans = ans * power(b, m) % MOD;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> k >> n >> m;
    init();
    cout << solve();
    return 0;
}