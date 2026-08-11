#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x:a)
        cin >> x;
    sort(a.begin(), a.end());

    using minHeap = priority_queue<int, vector<int>, greater<int>>;
    unordered_map<ll, minHeap> group;
    
    for(ll &x :a){
        int len = 1;

        auto it = group.find(x - 1);
        if(it!=group.end() && !it->second.empty()){
            len = it->second.top() + 1;
            it->second.pop();
        }
        group[x].push(len);
    }

    ll ans = n;
    for(auto &[_,heap]:group){
        if(!heap.empty()){
            ans = min(ans, heap.top());
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}