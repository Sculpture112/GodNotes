#include <bits/stdc++.h>
using namespace std;
int n, k, m;
const int MAXN = 20010;
int value[MAXN];
int cnt[MAXN];
void solve()
{
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> m;
    for (int i = 1; i <= n;i++){
        cin >> cnt[i] >> value[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    

    return 0;
}