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
    vector<pair<string, string>> a;
    for (int i = 0; i < n; i++) {
        string name, s;
        cin >> name >> s;
        name = name.substr(0, 2);
        a.push_back({name, s});
    }

    int cnt = 0;
    for(auto [name,s] : a){
        for(auto[name1,s1]:a){
            if(name == s1 && s == name1){
                cnt++;
            }
        }
    }
    cout << cnt;
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