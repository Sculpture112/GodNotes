#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> arr;
void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        arr.resize(n);
        bool haszero = false;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 0)
                haszero = true;
        }

        if (haszero)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<int> cost;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];

            int c3 = (3 - (x % 3)) % 3;
            int c9 = (9 - (x % 9)) % 9;

            ans = min(ans, c9);
            cost.push_back(c3);
        }

        sort(cost.begin(), cost.end());
        if (n >= 2)
        {

            ans = min(ans, cost[0] + cost[1]);
        }
        cout << ans << "\n";
    }

    return 0;
}