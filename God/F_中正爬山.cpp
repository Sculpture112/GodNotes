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

    vector<pair<ll, ll>> stack;
    vector<pair<ll, ll>> t;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        t.push_back({a, b});
    }
    sort(t.begin(), t.end());

    stack.push_back({t[0].first, t[0].second});
    for (int i = 1; i < n; i++)
    {
        auto [a, b] = t[i];
        // cout << a << " " << b;
        auto [l, r] = stack.back();
        stack.pop_back();
        if (a <= r)
        {
            a = min(l, a);
            b = max(r, b);
            // cout << a << " " << b << "\n";
            stack.push_back({a, b});
        }
        else
        {
            stack.push_back({l, r});
            stack.push_back({a, b});
        }
    }
    ll ans = 0;
    while (!stack.empty())
    {
        auto cur = stack.back();
        ll l = cur.first;
        ll r = cur.second;
        // cout << l << " " << r;
        stack.pop_back();
        ans += (r - l);
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