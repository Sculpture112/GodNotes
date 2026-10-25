#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    int cnt = 0;
    int mex = 0;
    for (int &x : a)
    {
        cnt++;
        if (mex == x && cnt >= k)
        {
            mex++;
            cnt -= k;
        }
    }

    cout << mex << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}