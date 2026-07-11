#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int sum(int x)
{
    int cnt0 = 0;
    int ans = 0;
    while (x != 0)
    {
        bool s = false;
        int u = x % 10;

        if (u == 8)
        {
            ans += 6;
            s = true;
        }
        else if (u == 9)
        {
            ans += 6;
            s = true;
        }
        else if (u == 6)
        {
            ans += 5;
            s = true;
        }
        else if (u == 0)
        {
            cnt0++;
            s = true;
        }

        if (!s)
        {
            ans += u;
        }
        x /= 10;
    }
    ans += cnt0 * 7;
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    cout << sum(n);
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