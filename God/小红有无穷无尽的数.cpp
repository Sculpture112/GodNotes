#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const int MOD = 998244353;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    int len = r - l + 1;
    if (len > 9)
    {
        l = r - 9;
    }
    string ans;
    r--, l--;
    for (int i = l; i <= r; i++)
    {
        ans.push_back(s[(i % n)]);
    }
    cout << ans<<"\n";
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