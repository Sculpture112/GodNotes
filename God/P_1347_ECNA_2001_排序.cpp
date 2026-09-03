#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int topo(int n,bool graph[26][26],string& word){
    int indegree[26]={};

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(graph[i][j])
                indegree[j]++;
        }
    }

    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bool graph[26][26];

    for (int relation = 1; relation <= m; relation++)
    {
        string s;
        cin >> s;
        int u = s[0] - 'A';
        int v = s[2] - 'A';

        if(!graph[u][v])
        {
            graph[u][v] = true;
            continue;
        }

        string order;
        int result = 
    }

    return 0;
}