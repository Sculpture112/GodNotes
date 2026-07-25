#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> time(n);
    vector<int> delay(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < q; i++) {
        cin>>quiery[i];
    }

    priority_queue<vector<pair<int,int>>,vector<pair<int,int>>,greater<vector<pair<int,int>>>> pq;
    for (int i = 1; i <= mx; i++) {
        while(pq.top == i)   
    }
    return 0;
}