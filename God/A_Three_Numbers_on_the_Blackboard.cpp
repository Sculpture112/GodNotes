#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int x = a[0], y = a[1], z = a[2];

    z = min(x + y, z);

    cout << z - x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}