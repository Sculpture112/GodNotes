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
    sort(gods.begin(), gods.end(), [](const auto &a, const auto &b)
         { return (a.value * 1.0 / a.weight) > (b.value * 1.0 / b.weight); });

    double ans = 0;
    for(auto x : gods){
        int weight = x.first, value = x.second;
        if(weight<=t){
            ans += value;
        }
        else if(t == 0){
            break;
        }
        else{
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}