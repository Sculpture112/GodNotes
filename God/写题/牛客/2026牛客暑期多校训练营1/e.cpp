#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll sum = 0;
    for (int i = 0, j = n - 1; i < n && j > 0; i++, j--)
    {
        sum -= 1LL * j * arr[i];
    }
    for (int i = n - 1, j = n - 1; i >= 0 && j > 0; i--, j--)
    {
        sum += 1LL * j * arr[i];
    }
    cout << sum;

    return 0;
}