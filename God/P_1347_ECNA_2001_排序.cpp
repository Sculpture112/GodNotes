#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL << 62;
const double DINF = 1e100;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    int m;
    cin >> n;
    cin >> m;

    bool reach[26][26] = {};

    for (int step = 1; step <= m; step++)
    {
        char a, op, b;
        cin >> a >> op >> b;
        reach[a - 'A'][b - 'A'] = true;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                }
            }
        }

        bool inconsistent = false;
        for (int i = 0; i < n; i++)
        {
            if (reach[i][i])
            {
                inconsistent = true;
                break;
            }
        }

        if (inconsistent)
        {
            cout << "Inconsistency found after " << step << " relations.\n";
            return;
        }

        bool determine = true;
        for (int i = 0; i < n && determine; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (!reach[i][j] && !reach[j][i])
                {
                    determine = false;
                    break;
                }
            }
        }

        if (determine)
        {
            vector<char> ans(n);
            for (int i = 0; i < n; i++)
            {
                int pre = 0;
                for (int j = 0; j < n; j++)
                {
                    if (reach[j][i])
                    {
                        pre++;
                    }
                }
                ans[pre] = i + 'A';
            }

            cout << "Sorted sequence determined after " << step << " relations: ";
            for (char c : ans)
            {
                cout << c;
            }
            cout << ".\n";
            return;
        }
    }

    cout << "Sorted sequence cannot be determined.\n";
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