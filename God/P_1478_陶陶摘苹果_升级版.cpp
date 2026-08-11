#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;
    a += b;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a >= arr[i].first && s >= arr[i].second)
        {
            s -= arr[i].second;
            ans ++;
        }
    }
    cout << ans;
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