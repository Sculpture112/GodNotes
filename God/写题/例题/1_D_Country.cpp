#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<ll> x(n), p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++)
    {
        prefix[i+1] = prefix[i] + p[i];
    }



    int q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        int left = lower_bound(x.begin(), x.end(), l) - x.begin();
        int right = upper_bound(x.begin(), x.end(), r) - x.begin();
        cout << prefix[right] - prefix[left] << "\n";
    }



    return 0;
}