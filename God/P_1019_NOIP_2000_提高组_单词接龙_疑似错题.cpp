#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
string s[25];
int overlap[25][25];
int addlen[25][25];
int used[25];
int ans = 0;
int n;

int overlapd(const string &a, const string &b)
{
    int limit = min(a.size(), b.size()) - 1;

    for (int len = 1; len <= limit; len++)
    {
        bool ok = true;
        for (int k = 0; k < len; k++)
        {
            if (a[a.size() - len + k] != b[k])
            {
                ok = false;
                break;
            }
        }

        if (ok)
            return len;
    }
    return 0;
}

void dfs(int last, int len)
{
    ans = max(ans, len);

    for (int i = 0; i < n; i++)
    {
        if (used[i] >= 2 || addlen[last][i] == 0)
            continue;

        used[i]++;
        dfs(i, len + addlen[last][i]);
        used[i]--;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    char c;
    cin >> c;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            overlap[i][j] = overlapd(s[i], s[j]);
            if (overlap[i][j])
            {
                addlen[i][j] = s[j].size() - overlap[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == c)
        {
            used[i]++;
            dfs(i, s[i].size());
            used[i]--;
        }
    }
    cout << ans;
    return 0;
}