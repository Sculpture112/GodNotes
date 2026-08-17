#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int a, b;
    cin >> a >> b;
    if(a+b ==9||a-b==9||a*b==9 || (a/b==9 && a%b == 0)){
        cout << "Nine";
        return;
    }
    cout << "Nein";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}