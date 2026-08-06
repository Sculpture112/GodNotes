#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int C2(int n)
{
    return n * (n - 1) / 2;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    if (m > n - 1)
    {
        cout << C2(n - 1) - (m - n + 1) << "\n";
    }
    else if (m == n - 1)
    {
        cout << C2(n - 1) << "\n";
    }
    else
    {
        cout << C2(m) << "\n";
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