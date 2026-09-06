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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    bool ok = false;

    vector<int> diff(n);
    vector<int> w(n);
    int fusum = 0;
    int zhsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            ok = true;
        }
        diff[i] = a[i] - b[i];
        if (diff[i] <= 0)
        {
            w[i] = 1;
            fusum += diff[i];
        }
        else
        {
            zhsum += diff[i];
        }
    }

    fusum = abs(fusum);

    if (ok)
    {
        cout << "Yes" << "\n";
        int k = (fusum + zhsum - 1) / zhsum + 1;
        for (int i = 0; i < n; i++) {
            if(w[i] != 1){
                w[i] = k;
            }
            cout << w[i] << " ";
        }
        return;
    }
    cout << "No";
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