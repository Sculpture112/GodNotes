#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    unordered_map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].size();j++){
            s[i][j] = tolower(s[i][j]);
        }
        cnt[s[i]]++;
    }

    int mx = 0;
    for(auto[_,ct]:cnt){
        mx = max(ct, mx);
    }
    cout << mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}