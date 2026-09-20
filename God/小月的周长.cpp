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
    int sum = 2 * n + 2 * m;
    if ((x == n || x == 1) && (y > 1 && y < n))
    {
        cout << sum + 2 << "\n";
        return;
    }
    if ((y == 1 || y == n) && (x > 1 && x < n))
    {
        cout << sum + 2 << "\n";
        return;
    }

    if ((x > 1 && x < n && y > 1 && y < n))
    {
        cout << sum + 4 << "\n";
        return;
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