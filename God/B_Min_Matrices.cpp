#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, k;
    cin >> n >> k;

    if (k < n || k > n + 2)
    {
        cout << -1 << "\n";
        return;
    }
    vector<vector<int>> graph(n, vector<int>(n, 0));

    int diff = k - n;

    if (diff == 0)
    {
        for (int i = 0; i < n; i++)
        {
            graph[i][i] = i + 1;
        }
    }
    else if(diff ==1){
        for(int )
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