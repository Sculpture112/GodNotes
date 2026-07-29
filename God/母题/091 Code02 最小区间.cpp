#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    struct Node{
        int v, i, j;
    };
    struct Compare{
        bool operator()(const Node& a,const Node& b)const{
            return a.v != b.v ? a.v < b.v : a.i < b.i;
        }
    };

    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size(),width =INT_MAX,right = 0,left =0;
        set<Node, Compare> set;
        for (int i = 0; i < k;i++)
            set.insert({nums[i][0], i, 0});
        
        while(set.size() == k){
            Node maxNode = *set.rbegin();
            Node minNode = *set.begin();
            set.erase(set.begin());
            if(maxNode.v - minNode.v<width){
                width = maxNode.v - minNode.v;
                left = minNode.v;
                right = maxNode.v;
            }

            if(minNode.j + 1<nums[minNode.i].size())
            {
                set.insert({nums[minNode.i][minNode.j + 1], minNode.i, minNode.j + 1});
            }
        }
        return {left, right};
    }
};
