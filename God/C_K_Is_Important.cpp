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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    int m = n;
    int pos = m - k + 1;

    vector<ll> sum(n + 2);
    for (int i = n; i >= 1; i--)
    {
        sum[i] = sum[i + 1] + a[i];
    }

    ans = sum[n - k - 1];
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