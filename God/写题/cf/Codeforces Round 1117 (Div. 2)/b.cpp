#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;

    for (int &x : a)
    {
        cin >> x;
    }
    for (int i = 1; i < n; i++)
    {
        sum += a[i - 1] - a[i] + 1;
    }
    sum += a[n - 1];
    vector<int> b(m);
    for (int &x : b)
        cin >> x;
    int sun = 0;
    for (int i = 1; i < m; i++)
    {
        sun += abs(b[i] - b[i - 1]) + 1;
    }
    sun += b[m - 1];
    if (sum < sun)
    {
        cout << 2 << "\n";
    }
    else
    {
        cout << 1 << "\n";
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