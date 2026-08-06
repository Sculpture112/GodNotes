#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const int MAXN = 251;

struct Tree
{
    int initial;
    int growth;
};

// 树的个数、天数最大值，不超过的量
Tree tree[MAXN];

// dp[i][j] : 在j天内，从前i棵树中选若干棵树进行砍伐，最大收益是多少
int dp[MAXN][MAXN];

int t, n, m;
#define all(x) (x).begin(), (x).end()

int compute()
{
    sort(tree + 1, tree + n + 1, [](const Tree &a, const Tree &b)
         { return a.growth < b.growth; });

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + tree[i].initial + tree[i].growth * (j - 1));
        }
    }
    return dp[n][m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m;
        for (int j = 1; j <= n; j++)
        {
            cin >> tree[j].initial;
        }
        for (int j = 1; j <= n; j++)
        {
            cin >> tree[j].growth;
        }
        cout << compute() << '\n';
    }
    return 0;
}
