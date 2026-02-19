```cpp
给定长度为 nn 的入栈序列pushedpushed 和长度为 nn 的出栈序列 poppedpopped，两者均为 1∼n1∼n 的排列。初始时栈为空，只允许在栈顶进行插入（入栈）和删除（出栈）操作；若可通过若干操作使出栈顺序等于 poppedpopped，则称 poppedpopped 为合法出栈序列。现有 qq 组测试，每组给定对应序列，判断 poppedpopped 是否为合法出栈序列。【名词解释】【排列】长度为 nn 的 排列 是由 1∼n1∼n 的 nn 个整数按任意顺序组成的序列，其中每个整数恰好出现一次。输入描述：第一行输入整数 q (1≦q≦5)q (1≦q≦5)，表示测试组数。接下来对于每组测试，依次输入：1.1.​一行整数 n (1≦n≦105)n (1≦n≦105)，表示序列长度；2.2.​一行 nn 个整数，为入栈序列 pushed1,…,pushednpushed1​,…,pushedn​；3.3.​一行 nn 个整数，为出栈序列 popped1,…,poppednpopped1​,…,poppedn​。输出描述：对于每组测试，输出一行，如果 poppedpopped 为合法出栈序列，则输出 YesYes；否则输出 NoNo。示例1输入：2
5
1 2 3 4 5
2 5 4 1 3
5
1 2 3 4 5
2 5 4 3 1
```
复制

输出：
```cpp
No
Yes
```

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n; cin >> n;
        vector<int> pushed, poped;
        pushed.resize(n);
        poped.resize(n);

        for (int j = 0; j < n; j++) cin >> pushed[j];
        for (int k = 0; k < n; k++) cin >> poped[k];

        stack<int> s;
        int idx = 0;

        // 修改点 1：把逻辑简化，每个数先老老实实入栈
        for (int j = 0; j < pushed.size(); j++) {
            s.push(pushed[j]);

            // 修改点 2：【核心】每入一个，就尝试连环弹出
            // 这里不能写 idx++ 在括号里，必须对上了才能加
            while (!s.empty() && s.top() == poped[idx]) { 
                s.pop();
                idx++; // 修改点 3：只有匹配成功，才让指针后移
            }
        } // 修改点 4：补上 for 循环的右括号

        // 此时，那个最后的 while(1) 已经不需要了，因为上面已经弹干净了
        if (!s.empty()) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
```