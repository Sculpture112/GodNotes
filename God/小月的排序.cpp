#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    auto cmp = [&](int x, int y)
    {
        if (x == 0 && y != 0)
        {
            return true;
        }
        if (y == 0 && x != 0)
        {
            return false;
        }
        // if (x == 0 && y == 0)
        //     return x == y;
        // int cnt = 0, cnt1 = 0;
        // for (int i = 31; i >= 0; i--)
        // {
        //     int mask = 1 << i;
        //     if (x & mask != 0)
        //     {
        //         cnt++;
        //     }
        //     if (y & mask != 0)
        //     {
        //         cnt1++;
        //     }
        // }
        // if (cnt != cnt1)
        // {
        //     return (cnt < cnt1) ? (x < y) : (x > y);
        // }

        // int pos = 0;
        // for (int i = 0; i < 32; i++)
        // {
        //     int mask = 1 << i;
        //     if (x & mask != 0)
        //     {
        //         pos = i;
        //         break;
        //     }
        // }
        // int pos1 = 0;
        // for (int i = 0; i < 32; i++)
        // {
        //     int mask = 1 << i;
        //     if (y & mask != 0)
        //     {
        //         pos1 = i;
        //         break;
        //     }
        // }
        // if (pos != pos1)
        // {
        //     return (pos < pos1) ? (x < y) : (x > y);
        // }

        // for (int i = 31; i > 0; i--)
        // {
        //     int mask = 1 << i;
        //     bool true1 = false, true2 = false;

        //     if (x & mask != 0)
        //     {
        //         true1 = true;
        //     }
        //     if (y & mask != 0)
        //     {
        //         true2 = true;
        //     }

        //     if (true1 && !true2)
        //     {
        //         return x < y;
        //     }
        //     if (!true1 && true2)
        //     {
        //         return x > y;
        //     }
        // }
    };
    cout << 1;

    // sort(a.begin(), a.end(), cmp);

    cout << a[k - 1];
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