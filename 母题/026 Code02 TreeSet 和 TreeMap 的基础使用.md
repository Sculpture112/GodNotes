# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]]

**难度 [[]]


```cpp
// 026 Code02 TreeSet 和 TreeMap 的基础使用

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // 设置 bool 输出格式为 true/false
    cout << boolalpha;

    // 底层红黑树
    map<int, string> treeMap;
    treeMap[5] = "这是5";
    treeMap[7] = "这是7";
    treeMap[1] = "这是1";
    treeMap[2] = "这是2";
    treeMap[3] = "这是3";
    treeMap[4] = "这是4";
    treeMap[8] = "这是8";

    cout << (treeMap.count(1) > 0) << "\n";
    cout << (treeMap.count(10) > 0) << "\n";
    cout << treeMap[4] << "\n";
    treeMap[4] = "张三是4";
    cout << treeMap[4] << "\n";

    treeMap.erase(4);
    // C++ 中用 count == 0 来判断不存在，对应 Java 的 == null
    cout << (treeMap.count(4) == 0) << "\n";

    cout << treeMap.begin()->first << "\n";
    cout << treeMap.rbegin()->first << "\n";

    // TreeMap中，所有的key，<= 4且最近的key是什么 (floorKey)
    // C++ 中 upper_bound(4) 返回第一个严格 > 4 的位置，往前退一格就是 <= 4 的最大值
    auto it_floor = treeMap.upper_bound(4);
    if (it_floor != treeMap.begin()) {
        --it_floor;
        cout << it_floor->first << "\n";
    }

    // TreeMap中，所有的key，>= 4且最近的key是什么 (ceilingKey)
    // C++ 中 lower_bound(4) 刚好返回第一个 >= 4 的位置
    auto it_ceil = treeMap.lower_bound(4);
    if (it_ceil != treeMap.end()) {
        cout << it_ceil->first << "\n";
    }

    cout << "========\n";

    // 命名为 mySet 避免与 std::set 冲突
    set<int> mySet;
    mySet.insert(3);
    mySet.insert(3);
    mySet.insert(4);
    mySet.insert(4);
    cout << "有序表大小 : " << mySet.size() << "\n";
    while (!mySet.empty()) {
        // C++ 需要分开获取和删除
        cout << *mySet.begin() << "\n";
        mySet.erase(mySet.begin());
        
        // 对应 Java 的 pollLast() 写法如下：
        // cout << *mySet.rbegin() << "\n";
        // mySet.erase(--mySet.end());
    }

    // 堆，Java 默认小根堆。如果要大根堆，定制比较器！
    // 注意：C++ 默认是大根堆！为了实现 Java 的默认小根堆效果，需传入 greater<int>
    priority_queue<int, vector<int>, greater<int>> heap1;
    heap1.push(3);
    heap1.push(3);
    heap1.push(4);
    heap1.push(4);
    cout << "堆大小 : " << heap1.size() << "\n";
    while (!heap1.empty()) {
        cout << heap1.top() << "\n";
        heap1.pop();
    }

    // 定制的大根堆，用比较器！
    // C++ 默认就是大根堆，直接写 priority_queue<int> 即可，
    // 这里为了对应代码展示，显式传入 less<int> 以表意大根堆。
    priority_queue<int, vector<int>, less<int>> heap2;
    heap2.push(3);
    heap2.push(3);
    heap2.push(4);
    heap2.push(4);
    cout << "堆大小 : " << heap2.size() << "\n";
    while (!heap2.empty()) {
        cout << heap2.top() << "\n";
        heap2.pop();
    }

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
