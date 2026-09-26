#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    string s;
    cin >> s;
    int one = -1, zero = -1;
    for (int i = 0; i < s.size();i++){
        if(zero == -1 &&s[i] == '0'){
            zero = i;
        }
        else if(one == -1 && s[i] == '1'){
            one = i;
        }
    }

    for (int i = 0; i < s.size();i++){
        if(i == one || i == zero){
            continue;
        }
        cout << s[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}