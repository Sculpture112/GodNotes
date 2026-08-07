#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200007;
int n, x;
void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        priority_queue<int> pq;

        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int c;
            cin >> c;
            ll avialiable = 1LL * (i - 1) * x;

            sum += c;
            pq.push(c);
            if (sum > avialiable)
            {
                sum -= pq.top();
                pq.pop();
            }
        }

        cout << pq.size() << "\n";
    }

    solve();

    return 0;
}