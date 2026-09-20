#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    int x, y;
    cin >> n >> m;
    cin >> x >> y;
    int sum = 0;
    if (y - 1 != 0 && x - 1 != 0)
    {
        sum += 2 * (y - 1 + x - 1);
    }
    if (m - y != 0 && x - 1 != 0)
    {
        sum += 2 * (m - y + x - 1);
    }
    if (n - x != 0 && y - 1 != 0)
    {
        sum += 2 * (n - x + y - 1);
    }
    if (m - y != 0 && n - x != 0)
    {
        sum += 2 * (m - y + n - x);
    }
    cout << sum << "\n";
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