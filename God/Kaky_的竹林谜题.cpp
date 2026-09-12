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
    if (n < 6)
    {
        cout << "No" << "\n";
        return;
    }

    vector<int> a;
    a.push_back(3);
    a.push_back(6);

    cout << "Yes" << "\n";
    for (int i = 2; i <= n; i += 2)
    {
        if (i != 6)
            a.push_back(i);
    }
    for (int i = 1; i <= n; i += 2)
    {
        if (i != 3)
            a.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << " \n"[i == 0];
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