#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0;
    int cnt = 0;
    for (int i = 0,cur = 0; i < n; i++) {
        if(s[i] == '.'){
            cur++;
            mx = max(cur, mx);
            cnt++;
        }
        else{
            cur = 0;
        }
    }

    if(mx >=3){
        cout << 2 << "\n";
    }
    else{
        cout << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}