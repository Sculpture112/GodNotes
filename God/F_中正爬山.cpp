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

    vector<pair<int, int>> stack;
    vector<pair<int, int>> t;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        t.push_back({a, b});
    }
    sort(t.begin(), t.end());

    stack.push_back({t[0].first, t[0].second});
    for (int i = 1; i < n; i++)
    {
        auto [a, b] = t[i];
        auto [l, r] = stack.back();
        stack.pop_back();
        if (l <= b)
        {
            l = min(l, a);
            stack.push_back({l, r});
        }
        else
        {
            stack.push_back({l, r});
            stack.push_back({a, b});
        }
    }
    int ans = 0;
    while (!stack.empty())
    {
        auto [l, r] = stack.back();
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