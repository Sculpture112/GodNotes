# []

> **原题链接:** (https://leetcode.cn/problems/meeting-rooms-ii/)

**涉及知识点:** [[贪心算法]], [[小根堆]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

```cpp
#include <bits/stdc++.h>

using namespace std;

// 会议室II
// 给你一个会议时间安排的数组 intervals
// 每个会议时间都会包括开始和结束的时间intervals[i]=[starti, endi]
// 返回所需会议室的最小数量
// 测试链接 : https://leetcode.cn/problems/meeting-rooms-ii/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& meeting) {
        int n = meeting.size();
        sort(meeting.begin(), meeting.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> heap;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!heap.empty() && heap.top() <= meeting[i][0]) {
                heap.pop();
            }
            heap.push(meeting[i][1]);
            ans = max(ans, (int)heap.size());
        }
        return ans;
    }
};
```

---
