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
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            c0++;
        else
        {
            c1++;
        }
    }

    if (abs(c1 - c0) > 2)
    {
        cout << -1 << "\n";
        return;
    }

    c1 = 0, c0 = 0;
    ll ans = 0;

    for (int i = 0, j; i < n; j++)
    {
        j = i + 1;

        while (j < n && s[j] == s[i])
        {
            j++;
        }

        if (j - i - 1 > 0 && s[i] == '0')
        {
            c0 += j - i - 1;
        }
        else if (j - i - 1 > 0 && s[i] == '1')
        {
            c1 += j - i - 1;
        }
        ans += j - i - 1;
        i = j;
    }
    if (abs(c1 - c0) >= 2)
    {
        ans += (max(c1, c0) - 1);
        ans -= min(c1, c0);
    }

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