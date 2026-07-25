#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m+1, -1);
    for (int i = 0; i < n; i++) {
        int c, sz;
        cin >> c >> sz;
        if(sz>cnt[c]){
            cnt[c] = sz;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i]<<" ";
    }
    while (T--) solve();

    return 0;
}