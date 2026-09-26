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
    vector<int> cnt(n + 1, 2);
    ll sum = 0;
    vector<int> a(2 * n);
    for (int &x : a)
        cin >> x;

    int start = 0;

    while (start != 2 * n)
    {
        int end = lower_bound(a.begin() + start + 1, a.end(), a[start]) - a.begin();

        if (end == 2 * n)
        {
            sum += 1;
        }
        else
        {
            sum += (end - start + 1) * (end - start + 1);
        }

        start = end + 1;
    }
    cout << sum << "\n";
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