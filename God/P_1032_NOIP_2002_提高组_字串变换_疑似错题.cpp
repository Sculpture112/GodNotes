#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

unordered_map<string, int> bfs(
    const string &start,
    const vector<pair<string, string>> &rule,
    bool reverse)
{
    unordered_map<string, int> dist;
    queue<string> q;

    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        string cur = q.front();
        q.pop();

        int step = dist[cur];
        if(step>=5)continue;

        for(auto& rul:rule){
            string from = reverse ? rul.second : rul.first;
            string to = reverse ? rul.first : rul.second;

            size_t pos = cur.find(from);
            while(pos != string::npos){
                string nxt = cur.substr(0, pos) + to + cur.substr(pos+from.size());
                if(!dist.count(nxt)){
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }

                pos = cur.find(from, pos + 1);
            }
        }
    }
    return dist;
}
void solve()
{
    string A, B;
    cin >> A >> B;
    vector<pair<string, string>> rule;
    string x, y;
    while (cin >> x >> y)
    {
        rule.push_back({x, y});
    }

    if (A == B)
    {
        cout << 0;
        return;
    }

    auto fromA = bfs(A, rule, false);
    auto fromB = bfs(B, rule, true);

    int ans = INF;
    for(auto& [s,d]:fromA){
        auto it = fromB.find(s);
        if(it!=fromB.end()){
            ans = min(ans, d + it->second);
        }
    }
    cout << ans;
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