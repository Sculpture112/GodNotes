```cpp
给定长度为 nn 的字符串 ss，其字符 si∈{R,D}si​∈{R,D} 表示第 ii 位参议员的阵营。其中 R 代表红帮，D 代表黑帮。参议员按照索引 11 到 nn 的顺序循环行动。若剩余有行动权的参议员均属于同一阵营，则该阵营获胜并结束流程；否则，当前参议员可选择：1.1.​ 弹劾一名仍可行动的参议员，使其在后续轮次中失去行动权。2.2.​ （仅当剩余参议员同阵营时）直接宣布胜利。你需要实现一个函数，求出所有参议员均采用最优策略时，最终获胜的阵营的名称。函数接受的参数为一个字符串 ss，长度 nn (1≦n≦104)(1≦n≦104)，且 si∈{R,D}si​∈{R,D}。函数的返回值为一个字符串 `Red` 或 `Dark`，分别表示红帮或黑帮获胜。示例1输入："DR"
```
复制

返回值：
```cpp
"Dark"
```
复制

说明：
```cpp
第 1 轮时，第一个参议员来自 Dark 阵营，他可以使用第一项权利禁止第二个参议员的权利这样第二个参议员就无法使用任何权利了。第 2 轮时，第一个参议员可以宣布胜利，因为他是唯一一个有投票权的人。
```

示例2

输入：
```cpp
"DRR"
```
复制

返回值：
```cpp
"Red"
```
复制

说明：
```cpp
第 1 轮时，第一个来自 Dark 阵营的参议员可以使用第一项权利禁止第二个参议员的权利第 2 轮时，第三个来自 Red 阵营的参议员可以使用他的第一项权利禁止第一个参议员的权利这样在第 3 轮只剩下第三个参议员拥有投票的权利，于是他可以宣布胜利。
```

```cpp
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.length();
        // 定义两个队列，分别存放红帮 (Red) 和黑帮 (Dark) 的参议员索引
        queue<int> red;
        queue<int> dark;

        // 1. 初始化队列
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                red.push(i);
            } else {
                dark.push(i);
            }
        }

        // 2. 模拟对决
        while (!red.empty() && !dark.empty()) {
            int r_idx = red.front();
            red.pop();
            int d_idx = dark.front();
            dark.pop();

            // 索引小的人先行使权力，弹劾对方
            if (r_idx < d_idx) {
                // 红帮获胜，将其索引 + n 重新加入队列，代表进入下一轮
                red.push(r_idx + n);
            } else {
                // 黑帮获胜，将其索引 + n 重新加入队列
                dark.push(d_idx + n);
            }
        }

        // 3. 返回最终获胜阵营
        return red.empty() ? "Dark" : "Red";
    }
};

// 简单的测试主函数
int main() {
    Solution sol;
    cout << "示例1 (DR): " << sol.predictPartyVictory("DR") << endl;    // 输出: Dark
    cout << "示例2 (DRR): " << sol.predictPartyVictory("DRR") << endl;  // 输出: Red
    return 0;
}
```