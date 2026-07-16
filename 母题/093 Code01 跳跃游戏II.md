# []
> **原题链接:** (https://leetcode.cn/problems/jump-game-ii/)
**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]
**核心套路:** 
## 破题切入点(思维闪念)
[]
```cpp
#include <bits/stdc++.h>
using namespace std;
// 跳跃游戏II
// 给定一个长度为n的整数数组nums
// 你初始在0下标，nums[i]表示你可以从i下标往右跳的最大距离
// 比如，nums[0] = 3
// 表示你可以从0下标去往：1下标、2下标、3下标
// 你达到i下标后，可以根据nums[i]的值继续往右跳
// 返回你到达n-1下标的最少跳跃次数
// 测试用例可以保证一定能到达
// 测试链接 : https://leetcode.cn/problems/jump-game-ii/
class Solution{public:int jump(vector<int>&arr){int cur=0,next=0,ans=0;for(int i=0;i<(int)arr.size();i++){if(cur<i)ans++,cur=next;next=max(next,i+arr[i]);}return ans;}};
```
---

