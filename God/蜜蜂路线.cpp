#include <bits/stdc++.h>
using namespace std;
int m, n;
bool visited[1001];
int dfs(int x)
{
    if (x == n)
    {
        return 1;
    }

    if(x-n>=3){
        return 0;
    }

    if(visited[x] =false){
        return 0;
    }

    for(int)

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;

    return 0;
}