# include <iostream>

```cpp
# P1618 三连击（升级版）## 题目描述将 $1, 2,\ldots, 9$ 共 $9$ 个数分成三组，分别组成三个三位数，且使这三个三位数的比例是 $A:B:C$，试求出所有满足条件的三个三位数，若无解，输出 `No!!!`。//感谢黄小U饮品完善题意## 输入格式三个数，$A,B,C$。## 输出格式若干行，每行 $3$ 个数字。按照每行第一个数字升序排列。## 输入输出样例 #1### 输入 #1```1 2 3```### 输出 #1```192 384 576219 438 657273 546 819327 654 981```## 说明/提示保证 $0 \le A<B<C \le 999$。---$\text{upd 2022.8.3}$：新增加二组 Hack 数据。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 检查三个数是否恰好使用了 1-9 每个数字一次
bool check(int a, int b, int c) {
    if (b > 999 || c > 999) return false; // 确保都是三位数
    int used[10] = {0};
    int nums[3] = {a, b, c};
    for (int n : nums) {
        while (n > 0) {
            int digit = n % 10;
            if (digit == 0 || used[digit]) return false; // 不能有0，不能重复
            used[digit] = 1;
            n /= 10;
        }
    }
    return true;
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool found = false;

    // A最小，n1最小从123开始，最大到987/C*A
    for (int n1 = 123; n1 <= 987; ++n1) {
        // 满足 n1:n2:n3 = A:B:C -> n2 = n1*B/A, n3 = n1*C/A
        // 必须能整除且比例正确
        if (n1 * B % A == 0 && n1 * C % A == 0) {
            int n2 = n1 * B / A;
            int n3 = n1 * C / A;
            if (check(n1, n2, n3)) {
                cout << n1 << " " << n2 << " " << n3 << endl;
                found = true;
            }
        }
    }

    if (!found) cout << "No!!!" << endl;
    return 0;
}
```
