#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int n;


void dfs(int least, int last)
{
    if(least == 0){
        cout << "\n";
        return;
    }
    for (int i = last; i < least;i++){
        cout << '+' << i;
        dfs(least - i, i);
    }
}
void solve()
{
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cout << i;
        dfs(n - i, i);
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