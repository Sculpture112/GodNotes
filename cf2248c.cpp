#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static void solve() {
    int n;
    cin >> n;

    const int m = 2 * n;
    vector<int> first(n + 1, 0);
    vector<int64> dp(m + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;

        dp[i] = dp[i - 1] + 1;

        if (first[x] == 0) {
            first[x] = i;
        } else {
            const int l = first[x];
            const int64 len = i - l + 1LL;
            dp[i] = max(dp[i], dp[l - 1] + len * len);
        }
    }

    cout << dp[m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
