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
    map<pair<string, string>, ll> cnt;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        string city, state;
        cin >> city >> state;
        city = city.substr(0, 2);

        if (state == city)
            continue;

        ans += cnt[{city, state}];

        cnt[{state, city}]++;
    }
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