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
    ll max = 0;
    ll sum = 0;
    ll ans = -1;
    ll u;
    for (int i = 0; i < n; i++)
    {
        cin >> u;
        if (max < u)
            max = u;
        sum += u;

        if (ans == -1 && sum + max >= k)
        {
            ans = i + 1;
        }
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