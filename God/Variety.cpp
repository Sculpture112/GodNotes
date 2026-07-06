#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;
    vector<pair<int, int>> gem;

    for (int i = 0; i < n; i++)
    {
        int c, v;
        cin >> c >> v;
        gem.push_back({v, c});
    }

    sort(gem.rbegin(), gem.rend());

    vector<int> cnt(n + 1, 0);
    vector<int> addable(n);
    vector<int> removable(n);

    int colors = 0;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        auto [v, c] = gem[i];
        ans += v;
        cnt[c]++;
        if (cnt[c] == 1)
        {
            colors++;

        }
        else
        {
            removable.push_back(v);
        }
    }

    for (int i = k; i < n; i++)
    {
        auto [v, c] = gem[i];

        if (cnt[i] == 0)
        {
            addable.push_back(v);
            cnt[i] = -1;
        }
    }

    sort(removable.begin(), removable.end());
    sort(addable.rbegin(), addable.rend());

    int i = 0, j = 0;
    while(colors<m){
        ans -= removable[i];
        ans += addable[j];

        i++, j++;
        colors++;
    }
    cout << ans;

    return 0;
}