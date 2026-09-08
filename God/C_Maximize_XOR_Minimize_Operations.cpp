#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
void solve()
{
    int x, y;
    cin >> x >> y;
    ll sum = x + y;

    int ans = 0;

    int pos;
    int cnt = 0;
    bool first = false;
    for (int i = 31; i >= 0; i--)
    {
        if (x & 1 != 0 && !first)
        {
            pos = i;
        }

        if (y & 1 != 0)
        {
            cnt++;
        }
    }

    if (x == 0)
    {
        cout << cnt << " " << 0;
        cout << "\n";
        return;
    }

    for (int i = 31; i >= 0; i++)
    {
        if (1 << i)
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