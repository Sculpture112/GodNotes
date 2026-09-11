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
    if (n == 1 || n == 2)
    {
        cout << "No";
        return;
    }
    ll a = 76;
    ll ans = 1;
    
    a = a * pow(10, n - 2);
    cout << "Yes" << "\n";
    cout << a - 76 << " ";

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