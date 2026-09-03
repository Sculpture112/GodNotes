#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 27;
const int MAXM = 1005;

int n = 26, m;

string str[MAXM];
int a[MAXM], b[MAXM];
int eidArr[MAXM];

int head[MAXN];
int nxt[MAXM];
int to[MAXM];
string weight[MAXM];
int cntg;

int cur[MAXN];
int inDeg[MAXN], outDeg[MAXN];

string path[MAXM];
int cntp;

int startnode(string s)
{
    return s[0] - 'a' + 1;
}

int endnode(string s)
{
    return s[s.size() - 1] - 'a' + 1;
}
bool edgecmp(int i, int j)
{
    if (a[i] != a[j])
    {
        return a[i] < a[j];
    }
    return str[i] < str[j];
}
void addedge(int u, int v, string word)
{
    nxt[++cntg] = head[u];
    head[u] = cntg;
    to[cntg] = v;
    weight[cntg] = word;
}
void connect()
{
    sort(eidArr + 1, eidArr + m + 1, edgecmp);

    for (int l = 1, r = 1; r <= m; l = ++r)
    {
        while (r + 1 <= m && a[eidArr[r + 1]] == a[eidArr[l]])
        {
            r++;
        }

        for (int i = r; i >= l; i--)
        { // 这里的遍历的 i 是虚拟坐标(根据eidArr)来的坐标
            int id = eidArr[i];
            int u = a[id];
            int v = b[id];
            string w = str[id];

            outDeg[u]++;
            inDeg[v]++;
            addedge(u, v, w);
        }
    }

    for (int i = 1; i <= n; i++)
    {                     // 意为每个首字母单词,这样后续可以直接通过to[参数] (这里实际上就是b[i]的意思)直接访问到下一个单词的首字母
        cur[i] = head[i]; // 为后续her算法准备弧
    }
}

int directedStart()
{
    int start = -1;
    int end = -1;

    for (int i = 1; i <= n; i++)
    {
        int diff = outDeg[i] - inDeg[i];

        if (diff > 1 || diff < -1)
            return -1;

        if (diff == 1)
        {
            if (start != -1)
                return -1;
            start = i;
        }

        if (diff == -1)
        {
            if (end != -1)
                return -1;
            end = i;
        }
    }

    if ((start == -1) != (end == -1))
        return -1;
    
    if(start != -1)
        return start;

    for (int i = 1; i <= n;i++){
        if(outDeg[i]>0){
            return i;
        }
    }
    return -1;
}

void euler(int u,const string& word){
    for (int e = cur[u]; e != 0;e = cur[u]){
        cur[u] = nxt[e];
        euler()
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> str[i];

        a[i] = startnode(str[i]);
        b[i] = endnode(str[i]);
        eidArr[i] = i;
    }

    connect(); // 数据离散化,数据放入进链式前项星,为her算法准备cur数组;

    int start = directedStart();

    if(start ==-1){
        cout << "***\n";
    }

    return 0;
}