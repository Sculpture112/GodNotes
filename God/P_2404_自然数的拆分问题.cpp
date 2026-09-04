#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int n;
vector<int> path;

void dfs(int sum, int last)
{
    for (int i = last; sum + i <= n && i < n; i++)
    {
        path.push_back(i);
        if (sum + i == n)
        {
            for (int i = 0; i < path.size(); i++)
            {
                if (i)
                    cout << '+';
                cout << path[i];
            }
            cout << "\n";
        }
        else
        {
            dfs(sum + i, i);
        }
        path.pop_back();
    }
}
void solve()
{
    cin >> n;

    dfs(0, 1);
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