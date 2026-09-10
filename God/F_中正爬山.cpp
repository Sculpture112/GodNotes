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

    vector<pair<int, int>> stack;
    vector<pair<int, int>> t;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
    }
    sort(t.begin(), t.end());

    for (int i = 0; i < n; i++)
    {
        auto [a, b] = t[i];
        while (!stack.empty())
        {
            auto [l, r] = stack.front();
            if(l<=b){
                
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