# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// 巴什博弈(SG函数求解过程展示)
// 一共有n颗石子，两个人轮流拿，每次可以拿1~m颗石子
// 拿到最后一颗石子的人获胜，根据n、m返回谁赢
// 对数器验证

// 发现结论去求解，时间复杂度O(1)
// 充分研究了性质
string bash1(int n, int m) {
    return n % (m + 1) != 0 ? "先手" : "后手";
}

// sg函数去求解，时间复杂度O(n*m)
// 不用研究性质
// 其实把sg表打印之后，也可以发现性质，也就是打表找规律
string bash2(int n, int m) {
    vector<int> sg(n + 1, 0);
    vector<bool> appear(m + 1, false);
    for (int i = 1; i <= n; i++) {
        fill(appear.begin(), appear.end(), false);
        for (int j = 1; j <= m && i - j >= 0; j++) {
            appear[sg[i - j]] = true;
        }
        for (int s = 0; s <= m; s++) {
            if (!appear[s]) {
                sg[i] = s;
                break;
            }
        }
    }

//		System.out.println("打印 n = " + n + ", m = " + m + " 的sg表");
//		for (int i = 0; i <= n; i++) {
//			System.out.println("sg(" + i + ") : " + sg[i]);
//		}

    return sg[n] != 0 ? "先手" : "后手";
}

// 为了验证
int main() {
    int V = 1000;
    int testTimes = 10000;
    cout << "测试开始" << '\n';
    for (int i = 0; i < testTimes; i++) {
        int n = rand() % V;
        int m = rand() % V;
        string ans1 = bash1(n, m);
        string ans2 = bash2(n, m);
        if (ans1 != ans2) {
            cout << "出错了!" << '\n';
        }
    }
    cout << "测试结束" << '\n';

    int n = 100;
    int m = 6;
    bash2(n, m);
    return 0;
}
```

---

