#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, k, n, m;
const int MOD = 10007;
ll ckn(ll k, ll n)
{
    ll ans = 1;
    ll chu = 1;
    for (int i = n; i >= 1; i--, k--)
    {
        ans *= k;
        chu *= i;
    }
    if (chu != 0)
        ans /= chu;
    ans %= MOD;
    return ans;
}

ll power(ll a, ll b)
{
    ll ans = 1;
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
    return ckn(k, n) * power(a, n) * power(b, m) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> k >> n >> m;

    cout << solve();
    return 0;
}