#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 3e6 + 5;
int tree[MAXN][62];
int endcount[MAXN];
int pass[MAXN];
int cnt;

void build()
{
    cnt = 1;
}
int getpath(char a)
{
    if (a <= 'z' && a >= 'a')
        return a - 'a';
    else if (a <= 'Z' && a >= 'A')
        return a - 'A' + 26;

    return a - '0' + 52;
}
void insertWord(const string &word)
{
    int cur = 1;
    pass[cur]++;
    for (int i = 0, path; i < word.size(); i++)
    {
        path = getpath(word[i]);
        if (tree[cur][path] == 0)
        {
            tree[cur][path] = ++cnt;
        }

        cur = tree[cur][path];
        pass[cur]++;
    }
    endcount[cur]++;
}

int searchWord(const string &word)
{
    int cur = 1;
    for (int i = 0, path; i < word.size(); i++)
    {

        path = getpath(word[i]);

        if (tree[cur][path] == 0)
        {
            return 0;
        }
        cur = tree[cur][path];
    }
    return endcount[cur];
}

int prefixNumber(const string &pre)
{
    int cur = 1;
    for (int i = 0, path; i < pre.size(); i++)
    {
        path = getpath(pre[i]);

        if (tree[cur][path] == 0)
        {
            return 0;
        }
        cur = tree[cur][path];
    }
    return pass[cur];
}

void deleteWord(const string &word)
{
    if (searchWord(word) > 0)
    {
        int cur = 1;
        pass[cur]--;
        for (int i = 0, path; i < word.size(); i++)
        {
            path = getpath(word[i]);

            if (--tree[cur][path] == 0)
            {
                return;
            }
            cur = tree[cur][path];
            pass[cur]--;
        }
        endcount[cur]--;
    }
}

void clearTrie()
{
    for (int i = 1; i <= cnt; i++)
    {
        fill(tree[i], tree[i] + 26, 0);
        endcount[i] = 0;
        pass[i] = 0;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    build();
    clearTrie();
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        insertWord(word);
    }
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;
        cout << prefixNumber(word) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}