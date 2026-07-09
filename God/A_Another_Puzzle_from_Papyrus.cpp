#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> a(n), b(n);
        int suma = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            suma += a[i];
        }
        int sumb = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sumb += b[i];
        }

        if(sumb>suma){
            cout << -1 << "\n";
            continue;
        }

        

        
    }
    solve();

    return 0;
}