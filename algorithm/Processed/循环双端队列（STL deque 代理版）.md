# 循环双端队列（STL deque 代理版）

```cpp
// 循环双端队列（STL deque 代理版）
#include <deque>
using namespace std;

class MyCircularDeque {
    deque<int> dq; int limit; // 底层容器与容量上限
public:
    MyCircularDeque(int k) : limit(k) {}

    // 插入头部：若满返回false，否则头部入队并返回true
    bool insertFront(int v) { if(dq.size() == limit) return false; dq.push_front(v); return true; }

    // 插入尾部：若满返回false，否则尾部入队并返回true
    bool insertLast(int v) { if(dq.size() == limit) return false; dq.push_back(v); return true; }

    // 删除头部：若空返回false，否则头部弹出并返回true
    bool deleteFront() { if(dq.empty()) return false; dq.pop_front(); return true; }

    // 删除尾部：若空返回false，否则尾部弹出并返回true
    bool deleteLast() { if(dq.empty()) return false; dq.pop_back(); return true; }

    // 获取头部：若空返回-1，否则返回头部值
    int getFront() { return dq.empty() ? -1 : dq.front(); }

    // 获取尾部：若空返回-1，否则返回尾部值
    int getRear() { return dq.empty() ? -1 : dq.back(); }

    // 判空
    bool isEmpty() { return dq.empty(); }

    // 判满
    bool isFull() { return dq.size() == limit; }
};

🗑️
```
