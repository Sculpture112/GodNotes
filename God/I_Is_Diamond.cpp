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
    vector<string> graph(n);
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    int ans = 0;
    auto check = [&](int x, int y)
    {
        int nx = x + k;
        int ny = y + k;
        for()
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ()
        }
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