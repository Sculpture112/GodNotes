# []

> **原题链接:** ()

**涉及知识点:** [[构造]], [[贪心算法]]，[[待补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

### 解法一：分类讨论法 (Case Analysis)

我们将卡牌分为两类：

- **基石组**：数量 $\ge 2$ 的卡牌种类数记为 **K**，它们的总数量记为 **P**。
    
- **单牌组**：数量 $= 1$ 的卡牌总张数记为 **S**。
    

根据 **K** 的数量，我们分三种情况讨论：

1. **当 K = 0 时（没有任何卡牌数量大于等于 2）：**
    
    全都是单牌。任取 3 张都会是不一样的，直接非法，**输出 0**。
    
2. **当 K = 1 时（只有一种卡牌数量大于等于 2，设其数量为 V）：**
    
    整个圆圈只有一种主色调，它自己首尾相连，没有和其他基石种类产生交界。
    
    这种情况下，每消耗 2 张基石卡牌，就能夹住 1 张单牌。
    
    因此，它能容纳的单牌容量为 `V / 2`（向下取整）。
    
    最大卡牌数 = **P + min(S, V / 2)**。
    
3. **当 K $\ge$ 2 时（有多种基石卡牌）：**
    
    这时候，不同的基石卡牌之间需要拼合（比如 `X` 连着 `Y`）。为了保证交界处合法，交界处的两端都必须保留至少 2 张纯色的基石卡牌。
    
    也就是说，每一种数量为 **c** 的基石卡牌，它能提供的单牌容量会缩水，具体容量公式为：$\lfloor c / 2 \rfloor - 1$。
    
    我们将所有基石卡牌的容量累加，得到总容量 **C**。
    
    最大卡牌数 = **P + min(S, C)**。
    

_(注意：无论哪种情况，最终算出的总张数如果小于 3，则无法构成符合题意的圆，必须输出 0。)_
解法一：
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long P = 0;
    long long K = 0;
    long long S = 0;
    long long C = 0;
    long long V = 0;

    for (int i = 0; i < n; ++i) {
        long long c;
        cin >> c;
        
        if (c == 1) {
            S++;
        } else {
            P += c;
            K++;
            C += (c / 2) - 1;
            V = c; 
        }
    }

    long long ans = 0;
    
    if (K == 0) {
        ans = 0;
    } else if (K == 1) {
        ans = P + min(S, V / 2);
    } else {
        ans = P + min(S, C);
    }

    if (ans < 3) {
        cout << 0 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int multTestQ;
    cin >> multTestQ;
    while (multTestQ--) {
        solve();
    }
    
    return 0;
}
```

### 解法二：统一对子思维 (Pairs Perspective)

我们换一个更极其巧妙的角度来思考：

既然所有规律都要求“两两相邻”，我们不如把所有数量 $\ge 2$ 的卡牌，每两张捆绑成一个“对子”。

对于数量为 **c** 的卡牌，它可以提供 $\lfloor c / 2 \rfloor$ 个对子。我们把所有种类的对子总数加起来，记为 **TotalPairs**。

- **如果要拼接出 K 种不同颜色的圆环**：
    
    我们需要拿恰好 **K** 个对子去充当不同颜色之间的“胶水”（也就是安全交界区）。
    
    剩下的 `TotalPairs - K` 个对子，每一个都可以独立去“领养”一张单牌！
    
- **特例**：如果 **K = 1**，因为整个圆环只有一种颜色，自己首尾相连，不需要跟其他颜色进行胶水拼接！所以 0 消耗，所有的 **TotalPairs** 都可以用来领养单牌。
    

这两种解法殊途同归，但都能极其优雅地在 $O(N)$ 的时间复杂度内解决问题。
解法二：
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long P = 0;          // 收纳盒1：记录所有基石卡牌（>=2）的总张数
    long long S = 0;          // 收纳盒2：记录所有单牌（=1）的总张数
    long long K = 0;          // 收纳盒3：记录基石卡牌的种类数
    long long totalPairs = 0; // 收纳盒4：记录全场一共能凑出多少个“对子”

    // 【第一部分：全局数据统计】
    for (int i = 0; i < n; ++i) {
        long long c;
        cin >> c;
        
        if (c == 1) {
            S++; 
        } else {
            P += c;              
            K++;                 
            totalPairs += c / 2; // 重点：不管三七二十一，先把所有能凑的对子全加起来！
        }
    }

    long long ans = 0;
    
    // 【第二部分：全局对子任务分配】
    if (K == 0) {
        ans = 0;
    } else if (K == 1) {
        ans = P + min(S, totalPairs);
    } else {
        ans = P + min(S, totalPairs - K);
    }

    // 【第三部分：底线防线】
    if (ans < 3) {
        cout << 0 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    // 优化输入输出流速度，竞赛必备
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int multTestQ;
    cin >> multTestQ;
    while (multTestQ--) {
        solve();
    }
    
    return 0;
}
```
---


