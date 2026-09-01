#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    string text, pattern;
    cin >> text >> pattern;

    text = " " + text;
    pattern = " " + pattern;
    int n = text.size() - 1;
    int m = pattern.size() - 1;

    vector<int> nxt(m + 1);
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j + 1])
        {
            j = nxt[j];
        }

        if (pattern[i] == pattern[j + 1])
        {
            j++;
        }

        nxt[i] = j;
    }

    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j > 0 && pattern[j + 1] != text[i])
        {
            j = nxt[j];
        }

        if (pattern[j + 1] == text[i])
        {
            j++;
        }

        if(j ==m){
            cout<<
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