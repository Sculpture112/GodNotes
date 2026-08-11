#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });
    int ans = 0;
    for (int i = 0, cur = 0; i < n; i++)
    {
        auto x = a[i];
        int f = x.first;
        int e = x.second;
        if(cur <= f){
            ans += 1;
            cur = e;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}