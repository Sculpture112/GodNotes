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
    vector<int> time(n), delay(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> delay[i];
    }
    int q;
    cin >> q;
    vector<int> quiery(q);
    for (int i = 0; i < q; i++) {
        cin>>quiery[i];
    }

    priority_queue<vector<int>,vector<int>,greater<vector<int>>> pq;
    for (int i = 1; i < n; i++) {
        
    }
    return 0;
}