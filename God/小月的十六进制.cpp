#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int getnum(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }
    return 0;
}
void solve()
{
    string s;
    int k;
    cin >> s;
    cin >> k;

    ll num = 0;
    size_t i = 0;
    ll cnt = 0;
    while (i != s.size())
    {
        char c = s[i++];
        num = getnum(c) + num *16;
    }

    for (int i = 0; i < k;i++){
        if(num%2!=0){
            cout << "NO";
            return;
        }
        num /= 2;
    }
    cout << "YES";
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