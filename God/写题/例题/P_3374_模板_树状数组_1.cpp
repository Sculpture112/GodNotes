#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500001;
int n, m;

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

int sum(int i){
    int ans = 0;
    while(i>0){
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

int edgesum(int i,int j ){
    return sum(j) - sum(i-1);
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

    for (int i = 1,a,b,c; i <= m;i++){
        cin >> a >> b >> c;
        if(a == 1){
            add(b, c);
        }
        else{
            cout << edgesum(b, c) << "\n";

        }
    }


    return 0;
}