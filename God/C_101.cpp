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
    vector<int> fu;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1){
            sign.push_back(i);
        }
        if(a[i] == -1){
            fu.push_back(i);
        }
    }

    int ans = 0;


    
    for (int i = 0; i < n-1; i++) {
        ans = max(ans,sign[i + 1] - sign[i]);
    }

    if(!fu.empty()){
        if(fu[0]<sign[0]){
            a[] = 1;
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