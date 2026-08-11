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
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int &x : a)
    {
        cin >> x;
        heap.push(x);
    }
    int ans = 0;
    while(heap.size() != 1){
        int cur = heap.top();
        heap.pop();
        cur += heap.top();
        heap.pop();
        heap.push(cur);
        ans += cur;
    }
    cout << ans;
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