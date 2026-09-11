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
    vector<int> a(k + 2);
    a[0] = 0;
    a[k + 1] = n + 1;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans = max((a[i] - a[i - 1]) / 2, ans);
    }
    ans = max(a[1] - a[0] - 1, ans);
    ans = max(a[k + 1] - a[k] - 1, ans);
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