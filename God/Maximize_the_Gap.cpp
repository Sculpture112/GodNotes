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

    
    return 0;
}
