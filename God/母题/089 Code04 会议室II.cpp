#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int minMeetingRooms(vector<vector<int>> &meeting)
{
    int n = meeting.size();
    sort(meeting.begin(), meeting.end(), [](const auto& a, const auto& b)
         { return a[0] < b[0]; });

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while(!pq.empty() && pq.top()<=meeting[i][0]){
            pq.pop();
        }

        pq.push(meeting[i][1]);
        ans = max(ans, (int)pq.size());
    }
    return ans;
}
