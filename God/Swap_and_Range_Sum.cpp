#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 200001;
int tree[MAXN];

int lowbit(int i)
{
    return i & -i;
}

void add(int i, int v)
{
    while (i <= n)
    {
        tree[i] += v;
        i += lowbit(i);
    }
}

int sum(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

int range(int l, int r)
{
    return sum(r) - sum(l - 1);
}

void swap(int x){
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, v; i <= n; i++)
    {
        cin >> v;
        add(i, v);
    }

    for (int i = 1,a,b,c; i <= m; i++)
    {
        cin >> a;
        if(a==1){

        }
    }

    return 0;
}