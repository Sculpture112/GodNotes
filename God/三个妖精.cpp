#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const int MOD = 998244353;
#define all(x) (x).begin(), (x).end()
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = n * (n - 1) * (n - 2);
    cout << ans;
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