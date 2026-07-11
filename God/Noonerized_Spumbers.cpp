#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int bit(int x)
{
    int bits = 0;
    while (x != 0)
    {
        x /= 10;
        bits++;
    }
    return bits;
}
int a, b, c;
void xtoy(int &x, int &y)
{
    y = y * 10 + x % 10;
    x /= 10;
}
void solve()
{
    char o;
    char w;
    cin >> a >> o >> b >> w >> c;
    if (o == '+')
    {
        int mx = max({bit(a), bit(b), bit(c)});
        int st;
        if (bit(a) == mx)
        {
            st = 0;
        }
        else if (bit(b) == mx)
        {
            st = 1;
        }
        else
        {
            st = 2;
        }

        bool ans = false;
        if (st == 0)
        {
            int x = a;
            int y = b;
            int z = c;
            while (x != 0)
            {
                xtoy(x, y);
                if (x + y == z)
                {
                    cout << x << " + " << y << " = " << z;
                    return;
                }
            }
            x = a, y = b, z = c;
            while (x != 0)
            {

                xtoy(x, z);
                if (x + y == z)
                {
                    cout << x << " + " << y << " = " << z;
                    return;
                }
            }
        }
        else if (st == 1)
        {
            int x = a, y = b, z = c;
            while(y!=0){
                xtoy(y, x);
                if(x + y == z){
                    cout << x << " + " << y << " = " << z;
                    return;
                }
            }
            x = a, y = b, z = c;
            while(y!=0){
                xtoy(y, z);
                if(x+y==z){
                    cout << x << " + " << y << " = " << z;
                    return;
                }
            }
        }
        else
        {
            int x = a, y = b, z = c;
            while(z !=0){
                xtoy(z, x);
                if(x + y ==z){
                    cout << x << " + " << y << " = " << z;
                    return;
                }
            }
            while(z!=0){
                xtoy(z, y);
                if(x+y == z){
                    cout << x << " + " << y << " = " << z;
                    return;
                }
            }
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