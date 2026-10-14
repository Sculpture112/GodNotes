#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const double INF = 1e100;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;

    vector<ll> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    auto distance = [&](int a, int b)
    {
        int dx = x[a] - x[b];
        int dy = y[a] - y[b];

        return sqrt(dx * dx + dy * dy);
    };

    vector<ll> diststart(n);

    for (int i = 0; i < n; i++)
    {
        diststart[i] = sqrt(x[i] * x[i] + y[i] * y[i]);
    }

    vector<vector<double>> dist(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = distance(i, j);
        }
    }

    int total = 1 << n;
    vector<vector<double>> dp(total, vector<double>(n, INF));

    for (int mask = 0; mask < total; mask++)
    {

        for (int last = 0; last < n; last++)
        {
            if (!(mask & (1 << last)))
            {
                continue;
            }

            for (int nxt = 0; nxt < n; nxt++)
            {
                if (mask & (1 << nxt))
                {
                    continue;
                }

                int newmask = mask | nxt;

                dp[newmask][nxt] = min(dp[newmask][nxt], dp[mask][last] + dist[last][nxt]);
            }
        }
    }

    double ans = INF;
    for (int i = 0; i < n;i++){
        ans = min(ans, dp[total - 1][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}