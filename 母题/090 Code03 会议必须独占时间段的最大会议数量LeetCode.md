# []
> **原题链接:** (https://leetcode.cn/problems/non-overlapping-intervals/)
**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]
**核心套路:** 
## 破题切入点(思维闪念)
[]
```cpp
#include <bits/stdc++.h>
using namespace std;
// 会议必须独占时间段的最大会议数量
// 给定若干会议的开始、结束时间
// 你参加某个会议的期间，不能参加其他会议
// 返回你能参加的最大会议数量
// 同学找到了Leetcode的在线测试，题意类似
// 测试链接 :https://leetcode.cn/problems/non-overlapping-intervals/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& meeting){sort(meeting.begin(),meeting.end(),[](auto&a,auto&b){return a[1]<b[1];});int ans=0,cur=INT_MIN;for(auto&e:meeting)if(cur<=e[0])ans++,cur=e[1];return meeting.size()-ans;}
};
```
---

