#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> primedevide(n + 1);

    for (int p = 2; p <= n; p++)
    {
        if (primedevide[p].empty())
        {
            for (int muiltiple = p; muiltiple <= n; muiltiple += p)
            {
                primedevide[muiltiple].push_back(p);
            }
        }
    }

    vector<ll> dp(n + 1, 0);

    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = LLONG_MAX;
        for (int j : primedevide[i])
        {
            dp[i] = min(dp[i], 1LL + 1LL * j * dp[i / j]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans += dp[x];
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}