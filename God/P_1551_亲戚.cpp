#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 5005;
int father[MAXN];

int findfather(int x){
    if(father[x] == x){
        return x;
    }
    return findfather(father[x]);
}
void unite(int x,int y){
    int fx = findfather(x);
    int fy = findfather(y);

    if(fx!=fy){
        father[fx] = fy;
    }
}
bool isunite(int x,int y){
    return (findfather(x) == findfather(y));
}
void solve() {
    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }
    for (int j = 0; j < p; j++) {
        int x, y;
        cin >> x >> y;
        if(isunite(x,y)){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }
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