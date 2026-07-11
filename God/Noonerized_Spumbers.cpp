#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int bit(int x){
    int bits = 0;
    while(x!=0){
        x /= 10;
        bits++;
    }
    return bits;
}
int a, b, c;
void xtoy(int x,int y){
    
}
void solve()
{
    char o;
    char w;
    cin >> a >> o >> b >> w >> c;
    if(o == '+'){
        int mx = max({bit(a),bit(b),bit(c)});
        int st;
        if(bit(a) == mx){
            st = 0;
        }
        else if(bit(b) ==mx){
            st = 1;
        }
        else{
            st = 2;
        }
        
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