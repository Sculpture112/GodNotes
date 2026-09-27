#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    int cnt = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(gcd(a[i],b[i])!=1){
                cnt++;
            }
        }
    }
    if(cnt>n-cnt){
        cout << "Alice";
    }
    else{
        cout << "Bob";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}