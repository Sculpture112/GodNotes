#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int&x:a)
        cin >> x;

    int retain = a[0] - x;
    if(retain<0){
        cout << "No"<<"\n";
        return;
    }
    for (int i = 1; i < n;i++){
        int cost = x;
        cost -= retain;
        if(cost<=0){
            retain = a[i];
            continue;
        }
        else{
            retain = a[i] - cost;
        }
        if(retain<0){
            cout << "No" << "\n";
            return;
        }
    }
    cout << "Yes" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}