#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int n, m;
const int MAXN = 1005;
int p[MAXN];

int findp(int x){
    if(x == p[x]){
        return x;
    }
    return findp(p[x]);
}
void unite(int x,int y){
    int fx = findp(x);
    int fy = findp(y);
    if(fx!=fy){
        p[fx] = fy;
    }
}
void solve() {
    if(n==1)
    {
        cout << 0 << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if(i == findp(i)){
            cnt++;
        }
    }
    cout << cnt - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin>>n && n!=0){
        cin >> m;
        solve();
    }

    return 0;
}