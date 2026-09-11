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
    if (n < 10)
    {
        cout << "No" << "\n";
        return;
    }
    
    vector<int> a(n);

    for (int i = 0; i <= n / 2; i++)
    {
        a[i] = (i + 1) * 2;
    }
    swap(a[n / 2 - 1], a[n / 2 - 2]);

    for (int i = )
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