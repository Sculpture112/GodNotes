#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    if(n == 1){
        cout << 1 << " " << 1 << "\n";
        cout << -1 * a[0] << "\n";
    }

    cout << "1 1\n";
    cout << 2 << " " << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] * (n - 1) << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < n; i++) {
        cout << -a[i] * n << " ";
    }
    cout << "\n";
    return 0;
        
}