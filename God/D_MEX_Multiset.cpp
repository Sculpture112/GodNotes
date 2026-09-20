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
    int zero = 0;
    for (int &x : a)
    {
        cin >> x;
        if (x == 0)
        {
            zero++;
        }
    }

    if (zero == 1)
    {
        cout << "NO\n";
        return;
    }
    string ans(n, 'A');

    bool firstzero = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && !firstzero)
        {

            firstzero = true;
            ans[i] = 'B';
        }
        if (a[i] == 0)
        {
            ans[i] = 'C';
        }
    }
    cout << "YES\n";
    cout << ans << "\n";
    
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