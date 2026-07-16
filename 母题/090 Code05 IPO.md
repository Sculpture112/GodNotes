# []
> **原题链接:** (https://leetcode.cn/problems/ipo/)
**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]
**核心套路:** 
## 破题切入点(思维闪念)
[]
```cpp
#include <bits/stdc++.h>
using namespace std;
// IPO
// 给你n个项目，对于每个项目i
// 它都有一个纯利润profits[i]
// 和启动该项目需要的最小资本capital[i]
// 最初你的资本为w，当你完成一个项目时，你将获得纯利润，添加到你的总资本中
// 总而言之，从给定项目中选择最多k个不同项目的列表
// 以最大化最终资本，并输出最终可获得的最多资本
// 测试链接 : https://leetcode.cn/problems/ipo/
class Solution{struct P{int p,c;};public:int findMaximizedCapital(int k,int w,vector<int>&profit,vector<int>&cost){priority_queue<P,vector<P>,function<bool(P,P)>> locked([](P a,P b){return a.c>b.c;}),open([](P a,P b){return a.p<b.p;});for(int i=0;i<(int)profit.size();i++)locked.push({profit[i],cost[i]});while(k--){while(!locked.empty()&&locked.top().c<=w)open.push(locked.top()),locked.pop();if(open.empty())break;w+=open.top().p;open.pop();}return w;}};
```
---

