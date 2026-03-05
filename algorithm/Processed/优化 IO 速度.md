# 优化 I/O 速度

> 设某汉字由 N×N 的 0 和 1 的点阵图案组成。我们依照以下规则生成压缩码。连续一组数值：从汉字点阵图案的第一行第一个符号开始计算，按书写顺序从左到右，由上至下。第一个数表示连续有几个 0，第二个数表示接下来连续有几个 1，第三个数再接下来连续有几个 0，第四个数接着连续几个 1，以此类推……例如: 以下汉字点阵图案：0001000
> 0001000
> 0001111
> 0001000
> 0001000
> 0001000
> 1111111

对应的压缩码是： 7 3 1 6 1 6 4 3 1 6 1 6 1 3 7 （第一个数是 N，其余各位表示交替表示 0 和 1 的个数，压缩码保证 N×N= 交替的各位数之和）

输入格式

汉字点阵图（点阵符号之间不留空格）。

输出格式

输出一行，压缩码。

输入输出样例

输入 #1复制

> 0001000
> 0001000
> 0001111
> 0001000
> 0001000
> 0001000
> 1111111

输出 #1复制

> 7 3 1 6 1 6 4 3 1 6 1 6 1 3 7

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 优化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    string total_bits = "";

    // 1. 读取第一行，确定 N 的大小
    if (cin >> line) {
        total_bits += line;
    }

    int n = line.length();

    // 2. 读取剩余的 N-1 行
    for (int i = 1; i < n; ++i) {
        cin >> line;
        total_bits += line;
    }

    // 3. 输出 N
    cout << n << " ";

    // 4. 扫描统计
    // 题目要求第一个输出的是 '0' 的个数，所以我们假设当前正在统计 '0'
    char current_target = '0';
    int count = 0;

    for (char c : total_bits) {
        if (c == current_target) {
            count++;
        } else {
            // 遇到不同的字符，输出当前统计结果，并切换目标
            cout << count << " ";
            count = 1; // 新的一段已经有一个字符了（即当前字符 c）

            // 切换目标字符：如果是 '0' 变 '1'，是 '1' 变 '0'
            if (current_target == '0') {
                current_target = '1';
            } else {
                current_target = '0';
// 这里可以用异或写，挺巧的
            }
        }
    }

    // 5. 输出最后一段的计数
    cout << count << endl;

    return 0;
}
```
