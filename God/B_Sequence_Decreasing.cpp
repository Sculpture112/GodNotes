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
    vector<int> a(n);
    int mn = INF;
    bool zero = false;
    for (int &x : a)
    {
        cin >> x;
        if (x == 0)
            zero = true;
        if (x < mn)
        {
            mn = x;
        }
    }

    if (mn > n - 1)
    {
        cout << 0 << "\n";
        return;
    }

    cout << n << "\n";
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