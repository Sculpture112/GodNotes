#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5 + 5;
int a[MAXN],b[MAXN],tail[MAXN];
int where[MAXN];

int bs(int len,int num){
    int l = 0, r = len - 1, m, ans = -1;
    while (l<=r)
    {
        m = l + ((r - l) >> 1);
        if(tail[m]>=num){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        where[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        b[i] = where[b[i]];
    }

    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int find = bs(len, b[i]);
        if(find ==-1){
            tail[len++] = b[i];
        }
        else{
            tail[find] = b[i];
        }
    }
    cout << len;
    return 0;
}
