#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
void solve()
{
    ll x, y;
    cin >> x >> y;
    ll sum = x + y;
    ll cnt = x;
    ll ans = 0;

    int pos;
    for (int i = 31; i >= 0; i--)
    {
        if (x & 1 != 0)
        {
            pos = i;
            break;
        }
    }

    if (x == 0)
    {
        cout << y << " " << 0;
        cout << "\n";
        return;
    }

    for (int i = pos; i >= 0; i--)
    {
        if (((1 << i) <= sum) != 0){
            sum -= (1 << i);
            ans += (1 << i);
        }
    }

    y = sum - ans;
    x ^= y;
    cout << x << " "<<cnt - x<<"\n";
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