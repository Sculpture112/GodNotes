#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 5 * 10e4 + 5;

int cnt = 0;
int father[MAXN];
string name[MAXN];
map<string, int> id;
int findfather(int x)
{
    if (father[x] != x)
    {
        father[x] = findfather(father[x]);
    }
    return father[x];
}

void unite(int x, int y)
{
    // cout << x << " " << y << "\n";
    int fx = findfather(x);
    int fy = findfather(y);

    // cout << fx << " " << fy << "\n";

    if (fx != fy)
    {
        father[fy] = fx;
    }
}

int getid(const string &s)
{
    if (id.count(s))
    {
        return id[s];
    }

    int x = cnt++;
    id[s] = x;
    name[x] = s;
    return x;
}

void solve()
{
    string u;
    int fcnt = -1;
    while (cin >> u)
    {
        if (u == "$")
        {
            break;
        }
        char op = u[0];
        string s = u.substr(1);
        int x = getid(s);

        if (op == '#')
        {
            fcnt = x;
        }
        else if (op == '+')
        {
            unite(fcnt, x);
        }
        else
        {
            cout << s << ' ' << name[findfather(x)] << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < MAXN; i++)
    {
        father[i] = i;
    }
    solve();

    return 0;
}