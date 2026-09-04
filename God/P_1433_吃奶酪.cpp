#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const double DINF = 1e100;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    vector<double> diststart(n);

    for (int i = 0; i < n; i++)
    {
        diststart[i] = (x[i] * x[i] + y[i] * y[i]);
    }

    auto dist = [&](int a, int b)
    {
        double dx = (x[a] - x[b]);
        double dy = (y[a] - y[b]);
        return (dx * dx + dy * dy);
    };

    vector<vector<double>> distance(n, vector<double>(n, DINF));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            distance[i][j] = dist(i, j);
        }
    }

    vector<vector<double>> dp(n, vector<double>(n, DINF));

    for (int i = 0; i < n;i++){
        dp[1 << i][i] = diststart[i];
    }

    int total = 1 << n;
    for (int mask = 1; mask < total;mask++){
        for (int last = 0; last < n;last++){
            if(!(mask & (1<<last))) continue;

            for (int nxt = 0; nxt < n;nxt++){
                if(mask & (1<<nxt)) continue;

                int newmask = mask | nxt;
                dp[newmask][nxt] = min(dp[newmask][nxt], dp[mask][last] + distance[last][nxt]);
            }
        }
    }

    double ans = DINF;
    for (int i = 0; i < n;i++){
        ans = min(ans, dp[total - 1][i]);
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}