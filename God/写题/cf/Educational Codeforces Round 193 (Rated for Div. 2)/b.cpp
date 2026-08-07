#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n);
    int kinds = 0;
    int sim = 0;
    int pre = -1;
    for(int &num:a)
    {
        cin >> num;
        if(pre = num)
            sim++;
        if(cnt[num]++ == 0){
            kinds++;
        }
        pre = num;
    }

    if(kinds == 1){
        cout << 1 << "\n";
        return;
    }

    pre = a[0];
    int sta = -1;
    for (int i = 1; i < n; i++) {
        if(a[i] == pre && a[i+1] != a[i]){
            if(a[i+2] != a[i]){
                sta = 2;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}