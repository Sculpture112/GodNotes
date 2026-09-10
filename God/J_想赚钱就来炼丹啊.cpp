#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(n);
    int mina = INF, minb = INF, minc = INF;
    map<int, int> mapa,mapb,mapc;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mapa[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mapb[b[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        mapc[c[i]]++;
    }

    auto [cura,cnta] = *mapa.begin();
    auto [curb, cntb] = *mapb.begin();
    auto [curc, cntc] = *mapc.begin();

    for (int i = 0; i < n;i++){
        
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