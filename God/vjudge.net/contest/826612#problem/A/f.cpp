#include <bits/stdc++.h>
using namespace std;

int a, b, p, s;
void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> p;
    int sum = (int)pow(a, b) % p;
    cout << a << "^" << b << " mod " << p << "=" << sum;

    solve();

    return 0;
}