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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum = 0;
    int start = 0;
    int end = 10;

    while (end < n)
    {
        sort(a.begin() + start, a.begin() + end);
        start += 10;
        end += 10;
    }

    if (start < n)
    {
        sort(a.begin() + start, a.end());
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] != 1)
        {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
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