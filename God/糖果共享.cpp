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
    vector<pair<int, int>> time(n);
    vector<int> delay(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> time[i].first;
        mx = max(time[i].first, mx);
        time[i].second = i;
    }
    sort(time.begin(), time.end(), [](auto &a, auto &b)
         { return a.first < b.first; });
    for (int i = 0; i < n; i++)
    {
        cin >> delay[i];
    }
    int q;
    cin >> q;
    vector<int> quiery(q);
    for (int i = 0; i < q; i++)
    {
        cin >> quiery[i];
    }
    vector<int> ans(n + 1, -1);
    priority_queue<vector<pair<int, int>>, vector<pair<int, int>>, greater<vector<pair<int, int>>>> pq;
    for (int i = 1, j = 0; i <= mx; i++)
    {
        while (j < n && time[j].first <= i)
        {
            ans[time[j].second] = i;
            pq.push({delay[time[j].second], time[j].second});

            j++;
        }
        while (pq.top().first == i)
        {
            if (ans[pq.top().second + 1] == -1)
            {
                pq.push({delay[pq.top().second + 1], pq.top().second + 1});
                ans[pq.top().second + 1] = i;
            }
            pq.top();
        }
    }
    for(auto a : quiery){
        cout << ans[a] << "\n";
    }
    return 0;
}