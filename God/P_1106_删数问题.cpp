#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    string str;
    cin >> str;
    int k;
    cin >> k;
    vector<char> s;
    int n = str.size();
    for (int i = 0; i < str.size(); i++) {
        s[i] = str[i];
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n - k;i++){
        cout << s[i];
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