# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]]

**难度 [[]]


```cpp
// 026 Code01 HashSet 和 HashMap 的基础使用

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Student {
    int age;
    string name;

    Student(int a, string b) {
        age = a;
        name = b;
    }
};

int main() {
    // 让 C++ 的 cout 打印 bool 值时输出 true/false，而不是 1/0，以对齐 Java 的输出表现
    cout << boolalpha;

    // Integer、Long、Double、Float
    // Byte、Short、Character、Boolean
    // String等都有这个特征
    // （在 C++ 中为了模拟 Java 的 String 引用表现，这里使用指针）
    string* str1 = new string("Hello");
    string* str2 = new string("Hello");
    
    // false，因为是指向了不同的内存地址
    cout << (str1 == str2) << "\n";
    // true，因为它们的值是相同的
    cout << (*str1 == *str2) << "\n";

    unordered_set<string> set;
    set.insert(*str1);
    cout << (set.count("Hello") > 0) << "\n";
    cout << (set.count(*str2) > 0) << "\n";
    set.insert(*str2);
    // 因为 set 里面根据值去重，所以大小为 1
    cout << set.size() << "\n";
    set.erase(*str1);
    set.clear();
    cout << set.empty() << "\n";

    cout << "===========\n";

    unordered_map<string, string> map1;
    map1[*str1] = "World";
    cout << (map1.count("Hello") > 0) << "\n";
    cout << (map1.count(*str2) > 0) << "\n";
    cout << map1[*str2] << "\n";
    // Java 中不存在的 key get 会返回 null，C++ 中我们可以用 count 判断它是否不存在
    cout << (map1.count("你好") == 0) << "\n";
    map1.erase("Hello");
    cout << map1.size() << "\n";
    map1.clear();
    cout << map1.empty() << "\n";

    cout << "===========\n";

    // 一般在笔试中，未必需要申请哈希表
    unordered_map<int, int> map2;
    map2[56] = 7285;
    map2[34] = 3671263;
    map2[17] = 716311;
    map2[24] = 1263161;
    
    // 上面的map2行为，可以被如下数组的行为替代
    int arr[100] = {0};
    arr[56] = 7285;
    arr[34] = 3671263;
    arr[17] = 716311;
    arr[24] = 1263161;
    // 哈希表的增、删、改、查，都可以被数组替代，前提是key的范围是固定的、可控的
    cout << "在笔试场合中哈希表往往会被数组替代\n";

    cout << "===========\n";
    
    Student* s1 = new Student(17, "张三");
    Student* s2 = new Student(17, "张三");
    // 为了模拟 Java 中未重写 hashCode 时的内存地址比较行为，这里使用 Student 指针做 Key
    unordered_map<Student*, string> map3;
    map3[s1] = "这是张三";
    cout << (map3.count(s1) > 0) << "\n";
    cout << (map3.count(s2) > 0) << "\n"; // 输出 false，因为指针地址不同
    map3[s2] = "这是另一个张三";
    cout << map3.size() << "\n";
    cout << map3[s1] << "\n";
    cout << map3[s2] << "\n";

    // 释放堆内存，防止内存泄漏 (C++ 专属习惯)
    delete str1;
    delete str2;
    delete s1;
    delete s2;

    return 0;
}
```

---


**核心套路:** [[]]
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
