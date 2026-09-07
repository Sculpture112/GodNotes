#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 1 << 62;
const double DINF = 1e100;

#define all(x) (x).begin(), (x).end()

void solve()
{

    int n, q;
    cin >> n >> q;
    list<int> seq;
    vector<list<int>::iterator> pos(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        seq.push_back(x);
        pos[x] = prev(seq.end());
    }

    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;

        seq.erase(pos[x]);
        seq.push_back(x);
        pos[x] = prev(seq.end());
    }

    bool first = true;
    for (int num : seq)
    {
        if (!first)
        {
            cout << " ";
        }
        cout << num;
        first = false;
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