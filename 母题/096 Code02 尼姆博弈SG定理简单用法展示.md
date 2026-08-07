# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// 尼姆博弈(SG定理简单用法展示)
// 一共有 n 堆石头，两人轮流进行游戏
// 在每个玩家的回合中，玩家需要 选择任一 非空 石头堆，从中移除任意 非零 数量的石头
// 如果不能移除任意的石头，就输掉游戏
// 返回先手是否一定获胜
// 对数器验证

// 时间复杂度O(n)
// 充分研究了性质
string nim1(const vector<int>& arr) {
    int eor = 0;
    for (int num : arr) {
        eor ^= num;
    }
    return eor != 0 ? "先手" : "后手";
}

// sg函数去求解
// 过程时间复杂度高，但是可以轻易发现规律，进而优化成最优解
// 证明不好想，但是从sg表出发，去观察最终的解，要好做很多
string nim2(const vector<int>& arr) {
    int maxValue = 0;
    for (int num : arr) {
        maxValue = max(maxValue, num);
    }
    vector<int> sg(maxValue + 1, 0);
    vector<bool> appear(maxValue + 1, false);
    for (int i = 1; i <= maxValue; i++) {
        fill(appear.begin(), appear.end(), false);
        //对于一堆石子,可能出现的状况就是 0 - i(石子数量)
        for (int j = 0; j < i; j++) {
            appear[sg[j]] = true;
        }
        for (int s = 0; s <= maxValue; s++) {
            if (!appear[s]) {
                sg[i] = s;
                break;
            }
        }
    }
    // 打印sg表之后，可以发现，sg[x] = x
    // 那么eor ^= sg[num] 等同于 eor ^= num
    // 从sg定理发现了最优解
    int eor = 0;
    for (int num : arr) {
        eor ^= sg[num];
    }
    return eor != 0 ? "先手" : "后手";
}

// 为了验证
vector<int> randomArray(int n, int v) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = rand() % v;
    }
    return ans;
}

int main() {
    int N = 200;
    int V = 1000;
    int testTimes = 10000;
    cout << "测试开始" << '\n';
    for (int i = 0; i < testTimes; i++) {
        int n = rand() % N + 1;
        vector<int> arr = randomArray(n, V);
        string ans1 = nim1(arr);
        string ans2 = nim2(arr);
        if (ans1 != ans2) {
            cout << "出错了!" << '\n';
        }
    }
    cout << "测试结束" << '\n';
    return 0;
}
```

---

