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

    if (k < n || k > n + n - 1)
    {
        cout << -1 << "\n";
        return;
    }
    // vector<vector<int>> graph(n, vector<int>(n, 0));

    // int diff = k - n;

    // for (int i = 0; i < n+diff;i++){
    //     if(i-1 == n-1)
    //         break;
    //     if(i>diff){
    //         graph[i][i - 1] = i + 1;
    //     }
    // }

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++)
    {
        graph[i][i] = i + 1;
    }

    //     for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if(graph[i][j] ==0){
    //             graph[i][j] = ++k;
    //         }
    //     }
    // }
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