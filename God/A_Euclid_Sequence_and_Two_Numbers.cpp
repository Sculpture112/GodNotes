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
    for (int &x : a)
        cin >> x;

    sort(a.rbegin(), a.rend());
    bool valid = true;
    for (int i = 0; i <= n - 3; i++)
    {
        if (a[i + 2] != a[i] % a[i + 1])
        {
            valid = false;
        }
    }

    if (valid)
    {
        cout << a[0] << " " << a[1] << "\n";
    }
    else
    {
        cout << -1 << "\n";
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