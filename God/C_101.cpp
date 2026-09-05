#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sign;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1){
            sign.push_back(i);
        }

    }


    for (int i = 0; i < n;i++){
        if(a[i] == 1){

        }
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