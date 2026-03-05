# include <iostream>

```cpp
# P5743 【深基7.习8】猴子吃桃## 题目描述一只小猴买了若干个桃子。第一天他刚好吃了这些桃子的一半，又贪嘴多吃了一个；接下来的每一天它都会吃剩余的桃子的一半外加一个。第 $n$ 天早上起来一看，只剩下 $1$ 个桃子了。请问小猴买了几个桃子？## 输入格式输入一个正整数 $n$，表示天数。## 输出格式输出小猴买了多少个桃子。## 输入输出样例 #1### 输入 #1```4```### 输出 #1```22```## 说明/提示数据保证，$1\le n\le20$。

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int peaches = 1; // 第 n 天剩下的桃子

    // 从第 n-1 天倒推回第 1 天
    for (int i = 1; i < n; i++) {
        peaches = (peaches + 1) * 2;
    }

    cout << peaches << endl;
    return 0;
}
```
