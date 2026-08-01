#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

struct Game{
    int ki, bi, people = 0;
    int earn() const { return bi - (people + 1) * ki - people * ki; }
};

struct compare{
    bool operator()(const Game& a,const Game& b)const{
        return a.earn() < b.earn();
    }
};

int enough2(int n, vector<vector<int>> &games)
{
    priority_queue<Game, vector<Game>, compare> heap;
    for(auto& game :games){
        heap.push({game[0], game[1]});
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(heap.top().earn()<=0)
            break;
        Game cur = heap.top();
        heap.pop();
        ans += cur.earn();
        cur.people++;
        heap.push(cur);
    }
    return ans;
}
