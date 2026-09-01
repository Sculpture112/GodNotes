#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 21;
int tree[MAXN][26];

int endcount[MAXN];
int pass[MAXN];
int cnt;
void build()
{
    cnt = 1;
}
void clearTree()
{
    for (int i = 1; i <= cnt; i++)
    {
        fill(tree[i], tree[i] + 26, 0);
        endcount[i] = 0;
        pass[i] = 0;
    }
}

int inserttree(const string &word)
{
    int cur = 1;
    pass[cur]++;
    for (int i = 0,path; i < word.size(); i++) {
        path = word[i] - 'a';
        if(tree[cur][path] == 0){
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
        pass[cur]++;
    }
    endcount[cur]++;
}
int search(const string&word){
    int cur = 1;
    for (int i = 0,path; i < word.size(); i++) {
        path = word[i] - 'a';
        if(tree[cur][path] == 0){
            return 0;
        }
        cur = tree[cur][path];
    }
    return endcount[cur];
}
void solve(){
    int n;
    cin >> n;
    
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