# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

**触发条件：**

**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

```cpp
#include <bits/stdc++.h>

using namespace std;

// 读入long类型数字的注意点
// 讲解019的扩展，没有看过讲解019的同学去看一下
void f1() {
    cout << "f1函数测试读入" << '\n';
    // 尝试读入 : 131237128371723187
    // in.nval读出的是double类型
    // double类型64位
    // long类型也是64位
    // double的64位会分配若干位去表达小数部分
    // long类型的64位全用来表达整数部分
    // 所以读入是long范围的数，如果用以下的写法
    // in.nval会先变成double类型，如果再转成long类型，就可能有精度损耗
    double value;
    cin >> value;
    long long num = value;
    cout << num << '\n';
}

void f2() {
    cout << "f2函数测试读入" << '\n';
    // 尝试读入 : 131237128371723187
    // 直接读出字符串
    string str;
    cin >> str;
    // 然后把字符串转成long
    // 不可能有精度损耗
    long long num = stoll(str);
    cout << num << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    f1();
    f2();
    return 0;
}
```

---
