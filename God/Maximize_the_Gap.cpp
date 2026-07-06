#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    sort(segs.begin(),segs.end(),[](auto a,segs b{

    }))
    auto check = [&](ll x)
    {
        int lastr = -1;
        int cnt = 0;
        for (auto [l, r] : segs)
        {
            if (cnt == 0 || l >= lastr + x)
            {
                cnt++;
                lastr = r;
                if (cnt >= k)
                    return true;
            }
        }
        return false;
    };

    if (!check(1))
    {
        cout << -1 << "\n";
        return 0;
    }

    ll l = 1, r = 1000000001LL;
    ll mid;
    while (r - l > 1)
    {

        mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << mid << "\n";

    return 0;
}
