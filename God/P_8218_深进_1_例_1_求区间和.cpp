#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> sum(n + 1);

    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << "\n";
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