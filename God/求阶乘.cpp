#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k;
ll cntzero(ll x)
{
    ll res = 0;
    while (x)
    {
        x /= 5;
        res += x;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;

    ll l = 0, r = k * 5 + 5;

    while (r - l > 1)
    {
        int mid = r + l / 2;
        if (cntzero(mid) >= k)
            l = mid;
        else
        {
            r = mid;
        }
    }

    if (cntzero(l) == k)
    {
        cout << l;
    }
    else
    {
        cout << -1;
    }
    return 0;
}