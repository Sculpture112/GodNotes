#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 1e6 + 5;
int tree[MAXN][26];
int endcount[MAXN];
int pass[MAXN];
int cnt = 1;

void insertree(const string &word)
{
    int cur = 1;
    pass[cur]++;
    for (int i = 0, path; i < word.size(); i++)
    {
        path = word[i] - 'a';
        if (tree[cur][path] == 0)
        {
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
        pass[cur]++;
    }
    endcount[cur]++;
}

int searchtree(const string &word)
{
    int cur = 1;
    int ans = endcount[cur];
    for (int i = 0, path; i < word.size(); i++)
    {
        path = word[i] - 'a';
        if (tree[cur][path] == 0)
        {
            return 0;
        }
        cur = tree[cur][path];
        ans += endcount[cur];
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        insertree(word);
    }
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;
        cout << searchtree(word) << "\n";
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