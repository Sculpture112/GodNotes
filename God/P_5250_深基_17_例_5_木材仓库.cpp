#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    set<ll> wood;
    for (int i = 0; i < n; i++)
    {
        int op;
        ll t;
        cin >> op >> t;
        if (op == 1)
        {
            if (!wood.insert(t).second)
            {
                cout << "Already Exist\n";
            }
        }
        else
        {
            if (wood.empty())
            {
                cout << "Empty\n";
                continue;
            }

            auto right = wood.lower_bound(t);
            auto chosen = right;

            if (right == wood.begin())
            {
                chosen = right;
            }
            else if (right == wood.end())
            {
                chosen = prev(right);
            }
            else
            {
                auto left = prev(right);
                if (t - *left <= *right - t)
                {
                    chosen = left;
                }
            }
            cout << *chosen << "\n";
            wood.erase(chosen);
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