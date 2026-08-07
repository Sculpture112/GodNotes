#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;

    vector<ll> arr(1LL * n * m);
    priority_queue<ll, vector<ll>, greater<ll>> heap;
    for (ll &x : arr)
        cin >> x;
    ll sum = 0;
    ll ans = m;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            heap.push(arr[1LL * i * m +j]);
            sum += arr[1LL * i * m +j];
            if (heap.size() == ans)
            {
                sum -= heap.top();
                heap.pop();
            }
        }
        while (!heap.empty() && sum >= v[i])
        {
            ans = heap.size();
            sum -= heap.top();
            heap.pop();
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << "\n";

    return 0;
}