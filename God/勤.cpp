#include <bits/stdc++.h>
using namespace std;
int n, a, b;
void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    if(a+b<n){
        cout << 0;
        return 0;
    }
    cout << abs(b - (n - a));

    solve();

    return 0;
}