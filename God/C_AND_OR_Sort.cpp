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
    int start = s[0];
    if(s[0] == '1'){
        int cnt = 0;
        for (char c:s)
        {
            if(c=='0'){
                cnt++;
            }
        }
        cout << cnt << "\n";
        return;
    }
    int cnt = 0;
    for (int i = 1; i < s.length();i++){
        if(s[i-1] == '1'&& s[i] == '0'){
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}