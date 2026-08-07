#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> len(n + 1);
    vector<int> finish(n + 1);
    vector<vector<int>> g(n + 10);
    vector<int> in(n + 1);
    for (int i = 0; i < n; i++)
    {
        int id, length;
        cin >> id >> length;
        int pre;
        len[id] = length;
        while(cin>>pre && pre!=0){
            g[pre].push_back(id);
            in[id]++;
        }
    }

    vector<int> q(n+1);
    int l = 0, r = 0;
    for (int i = 1;i<=n;i++){
        if(in[i]==0){
            finish[i] = len[i];
            q[r++] = i;
        }
    }

    int ans = 0;
    while(l<r){
        int cur = q[l++];
        ans = max(ans,finish[cur]);
        for(int nxt:g[cur]){
            if(--in[nxt] == 0){
                q[r++] = nxt;
            }
            finish[nxt] = max(finish[nxt], finish[cur] + len[nxt]);
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