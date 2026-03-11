# P3184 [USACO16DEC] Counting Haybales S

## 题目描述
[[二分查找]]
Farmer John 刚刚将他的 $N$ 个干草捆（$1 \leq N \leq 100,000$）安排在他农场的一维道路上的各个位置。为了确保它们之间的间距合适，请帮助他回答 $Q$ 个查询（$1 \leq Q \leq 100,000$），每个查询询问在道路的特定区间内有多少个干草捆。

## 输入格式

第一行包含 $N$ 和 $Q$。

第二行包含 $N$ 个不同的整数，每个整数的范围在 $0 \ldots 1,000,000,000$ 之间，表示每个位置上有一个干草捆。

接下来的 $Q$ 行每行包含两个整数 $A$ 和 $B$（$0 \leq A \leq B \leq 1,000,000,000$），表示一个查询，询问在 $A$ 到 $B$（包括 $A$ 和 $B$）的区间内有多少个干草捆。

## 输出格式

你需要输出 $Q$ 行。对于每个查询，输出其对应区间内的干草捆数量。

## 输入输出样例 #1

### 输入 #1

```
4 6
3 2 7 5
2 3
2 4
2 5
2 7
4 6
8 10
```

### 输出 #1

```
2
2
3
4
1
0
```
```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // 按“数量”开数组：只开 n 个空间
    vector<int> pos(n); 
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    // 排序后，pos[0] 是最小的坐标，pos[n-1] 是最大的
    sort(pos.begin(), pos.end());

    while (q--) {
        int a, b;
        cin >> a >> b;
        
        // 在 pos 数组里二分查找坐标 a 和 b 的位置
        // upper_bound(b) 找到第一个 > b 的位置
        // lower_bound(a) 找到第一个 >= a 的位置
        auto right = upper_bound(pos.begin(), pos.end(), b);
        auto left = lower_bound(pos.begin(), pos.end(), a);
        
        // 两个指针相减，就是这两个坐标之间的干草捆数量
        cout << (right - left) << "\n";
    }

    return 0;
}
```