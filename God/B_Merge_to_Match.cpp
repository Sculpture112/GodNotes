#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int mn = INF, mx = 0;
    unordered_map<int, int> map;
    for (int &x : a)
    {
        cin >> x;
        if(x<mn)
            mn = x;
        if(x>mx)
            mx = x;
        map[x]++;
    }

    int omn = INF, omx = 0;

    int cnt = 0;
    for (int &x : b)
    {
        cin >> x;
        if(x<omn)
            omn = x;
        if(x>omx)
            omx = x;
        if(map.count(x))
            cnt++;
    }

    
    if(mn>omn || mx < omx || 2*(m - cnt) > n-cnt){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}