#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 200001;
int tree[MAXN];


int lowbit(int i ){
    return i & -i;
}

void add (int i,int v){
    while(i<=n){
        tree[i] += v;
        i += lowbit(i);
    }
}

void range(int)


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
    }

    return 0;
}