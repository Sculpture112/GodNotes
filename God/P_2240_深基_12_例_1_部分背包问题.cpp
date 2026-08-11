#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> weight(n);
    vector<int> value(n);
    vector<pair<int, int>> gods(n);
    for (int i = 0; i < n; i++) {
        cin >> gods[i].first >> gods[i].second;
    }
    sort(gods.begin(), gods.end(), [](const auto& a, const auto &b)
         { return (a.second * 1.0 / a.first) > (b.second * 1.0 / b.first); });

    double ans = 0;
    for(auto x : gods){
        int weight = x.first, value = x.second;
        if(weight<=t){
            ans += value;
            t -= weight;
        }
        else if(t == 0){
            break;
        }
        else{
            ans += (1.0 * t / weight) * value;
            t = 0;
        }
        
    }
    cout << fixed << setprecision(2) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}