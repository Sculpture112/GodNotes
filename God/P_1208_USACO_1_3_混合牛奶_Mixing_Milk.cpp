#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(sum + a[i].second<s){
            ans += (a[i].first * a[i].second);
            sum += a[i].second;
        }
        else{
            ans += (a[i].first * (s - sum));
            break;
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