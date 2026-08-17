#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    unordered_map<char, int> cnt(n);
    for (string& s:a){
        cin >> s;
        cnt[s[0] + 'A' - 'a']++;
    }
    vector<string> ans(m);
    for(string&s :ans)
        cin >> s;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < ans[i].size();j++){
            auto it = cnt.find(ans[i][j]);
            if(it == cnt.end()){
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}