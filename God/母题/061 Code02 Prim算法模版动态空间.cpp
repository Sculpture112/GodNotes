#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0, u, v, w; i < n; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    for(auto edge:graph[1]){
        heap.push({edge.first, edge.second});
    }

    vector<bool> set(n + 1, false);
    set[1] = true;
    int nodeCnt = 1;
    int ans = 0;
    while(!heap.empty()){
        auto [cost, nxt] = heap.top();
        heap.pop();


        if(!set[nxt])
        {
            nodeCnt++;
            ans += cost;
            set[nxt] = true;
            for (auto e : graph[nxt])
            {
                heap.push({e.first, e.second});
            }
        }
    }
    if(nodeCnt == n){
        cout << ans;
    }
    else{
        cout << "orz";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
