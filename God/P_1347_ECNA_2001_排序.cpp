#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int topo(int n, bool graph[26][26], string &order)
{
    int indegree[26] = {};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
                indegree[j]++;
        }
    }

    bool used[26] = {};
    order.clear();
    bool unique = true;

    for (int step = 0; step < n; step++)
    {
        vector<int> zero;

        for (int i = 0; i < n; i++)
        {
            if (!used[i] && indegree[i] == 0)
            {
                zero.push_back(i);
            }
        }

        if (zero.empty())
        {
            return -1;
        }

        if (zero.size() > 1)
        {
            unique = false;
        }

        int u = zero[0];
        used[u] = true;
        order.push_back('A' + u);

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v])
            {
                indegree[v]--;
            }
        }
    }
    return unique ? 1 : 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bool graph[26][26] = {};

    for (int relation = 1; relation <= m; relation++)
    {
        string s;
        cin >> s;
        int u = s[0] - 'A';
        int v = s[2] - 'A';

        if (graph[u][v])
        {
            continue;
        }
        graph[u][v] = true;

        string order;
        int result = topo(n, graph, order);

        if (result == -1)
        {
            cout << "Inconsistency found after "
                 << relation << " relations.\n";
            return 0;
        }

        if (result == 1)
        {
            cout << "Sorted sequence determined after "
                 << relation << " relations: "
                 << order << ".\n";
            return 0;
        }
    }

    cout << "Sorted sequence cannot be determined.\n";
    return 0;
}