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
        bool srt = false;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if(b[i]>a[i])
                srt = true;
            sumb += b[i];
        }

        if(sumb>suma){
            cout << -1 << "\n";
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        bool con = false;
        while(i<n){
            if(a[i]<b[j]){
                cout << -1 << "\n";
                con = true;
                break;
            }
            i++, j++;
        }
        if(con) continue;
        int ans = suma - sumb;
        if(srt)
        {
            cout << ans + c << "\n";
            continue;
        }
        cout << ans << "\n";

        // cout << ans << "\n";
    }
    solve();

    return 0;
}