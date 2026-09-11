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
    string s;
    cin >> s;
    int cnt = 0;
    int ans = INF;

    int sx = 0, sy = 0;
    bool ok = false;

    vector<pair<int, int>> fo;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        fo.push_back({a, b});
    }

    auto dist = [&](int x, int y)
    {
        return (abs(sx - x) + abs(sy - y));
    };
    for (char c : s)
    {
        if (c == 'N')
            cnt++;
        else if (c == 'R')
            sy++;
        else if (c == 'U')
            sx--;
        else if (c == 'D')
            sx++;
        else if (c == 'L')
            sy--;
        for (auto [x, y] : fo)
        {
            ans = min(ans, dist(x, y));
        }

        if (ans <= cnt)
        {
            cout << "坐标" << sx << " " << sy << " ";
            cout << ans << " " << cnt << "\n";
            ok = true;
        }
    }
    if (ok)
    {
        cout << "Yes" << "\n";
    }
    else
    {
        cout << "No" << "\n";
    }
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