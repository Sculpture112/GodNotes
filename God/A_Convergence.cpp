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

    vector<int> a(n);
    ll sum = 0;
    for (int &x : a)
    {
        cin >> x;
        sum += x;
    }

    sum /= n;

    auto it = find(a.begin(), a.end(), sum + 1) - a.begin();

    int ans = min(it, n - it);
    cout << ans << "\n";
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