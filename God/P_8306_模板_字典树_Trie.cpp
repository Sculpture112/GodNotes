#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 3e6 + 5;
int tree[MAXN][62];
int pass[MAXN];
int endcount[MAXN];
int cnt = 1;

int getchar(char c){
    if(c>='a' && c<='z'){
        return c - 'a';
    }else if(c>='A' && c<='Z'){
        return c - 'A' + 26;
    }
    return c - '0' + 52;
}
void insertword(const string&s){
    int cur = 1;
    pass[cur]++;
    for (int i = 0; i < s.size();i++){
        int path = getchar(s[i]);
        
        if(tree[cur][path]==0){
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
        pass[cur]++;
    }
    endcount[cur]++;
}
int precount(const string&s){
    int cur = 1;
    for (int i = 0; i < s.size(); i++) {
        int path = getchar(s[i]);
        
        if(tree[cur][path] == 0){
            return 0;
        }

        cur = tree[cur][path];
    }
    return pass[cur];
}
void solve()
{
    for (int i = 1; i <= cnt; i++)
    {
        fill(tree[i], tree[i] + 62, 0);
        pass[i] = endcount[i] = 0;
    }
    cnt = 1;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insertword(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << precount(s) << "\n";
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