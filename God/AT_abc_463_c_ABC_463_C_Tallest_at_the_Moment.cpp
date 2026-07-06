#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h(n), l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> l[i];
    }

    vector<int> suf(n+1, 0);
    suf[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0;i--)
    {
        suf[i] = max(suf[i + 1], h[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        int pos = upper_bound(l.begin(), l.end(), t) - l.begin();
        cout << suf[pos] << "\n";
    }

    return 0;
}