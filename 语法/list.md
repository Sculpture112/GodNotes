# C++ list 常见算法用法与语法

## 1. 基本概念

std::list<T> 是双向链表：

- 已知迭代器位置时，插入、删除通常是 O(1)。
- 不支持随机访问，不能使用 a[i] 或 a.at(i)。
- 插入或删除其他节点通常不会使已有迭代器失效；被删除节点的迭代器会失效。
- list 自带 sort、unique、merge 等成员函数，不能直接把 std::sort 用在 list 上。

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;
```

---

## 2. 创建与初始化

```cpp
list<int> a;                         // 空链表
list<int> b(5);                      // 5 个 0
list<int> c(5, 7);                   // 5 个 7
list<int> d{1, 2, 3, 4};             // 初始化列表
list<int> e(d);                      // 拷贝构造
list<int> f(d.begin(), d.end());     // 用迭代器区间构造

// C++17：类型较简单时可以使用 CTAD
list g{1, 2, 3};                     // 推导为 list<int>
```

```cpp
a.empty();       // 是否为空
a.size();        // 元素个数，O(1)
a.max_size();    // 理论上的最大元素个数
a.clear();       // 清空，O(n)
```

---

## 3. 访问首尾元素

```cpp
list<int> a{10, 20, 30};

int first = a.front();   // 10
int last = a.back();     // 30

a.front() = 100;
a.back() = 300;

if (!a.empty()) {        // front() 和 back() 要求非空
    cout << a.front() << ' ' << a.back() << '\\n';
}
```

list 没有 operator[] 和 at()。如果要访问第 k 个元素，只能移动迭代器：

```cpp
auto it = a.begin();
advance(it, k);                // 移动 k 步，复杂度 O(k)
cout << *it << '\\n';

auto it2 = next(a.begin(), k); // 不改变 a.begin() 本身
```

---

## 4. 遍历

```cpp
list<int> a{1, 2, 3, 4};

for (int x : a) {              // 只读或拷贝遍历
    cout << x << ' ';
}

for (int& x : a) {             // 修改元素要用引用
    x *= 2;
}

for (auto it = a.begin(); it != a.end(); ++it) {
    cout << *it << ' ';
}

for (auto it = a.rbegin(); it != a.rend(); ++it) {
    cout << *it << ' ';        // 反向遍历
}
```

end()、rend() 是尾后位置，不能解引用。

---

## 5. 头尾增删

```cpp
list<int> a{2, 3};

a.push_front(1);       // 1 2 3，O(1)
a.push_back(4);        // 1 2 3 4，O(1)
a.emplace_front(0);   // 直接在头部构造
a.emplace_back(5);    // 直接在尾部构造

a.pop_front();        // 删除头部，O(1)
a.pop_back();         // 删除尾部，O(1)
```

pop_front() 和 pop_back() 不返回被删除的值，需要先读取：

```cpp
if (!a.empty()) {
    int x = a.front();
    a.pop_front();
}
```

---

## 6. 指定位置插入

insert 和 emplace 的第一个参数是位置，元素插入到该迭代器之前。

```cpp
list<int> a{1, 4};
auto pos = next(a.begin());

a.insert(pos, 2);             // 1 2 4
a.insert(pos, 2, 3);          // 在 pos 前插入两个 3
a.insert(pos, {7, 8});        // 插入初始化列表

a.emplace(pos, 10);           // 直接构造元素
a.insert(a.end(), 100);        // 插入到尾部
```

---

## 7. 删除位置或区间

```cpp
list<int> a{1, 2, 3, 4, 5};

auto it = next(a.begin(), 2);
a.erase(it);                    // 删除 3，返回下一个迭代器

auto first = next(a.begin(), 1);
auto last = next(a.begin(), 3);
a.erase(first, last);           // 删除下标 [1, 3) 的元素

a.clear();                      // 删除所有元素
```

---

## 8. 按值或按条件删除

```cpp
list<int> a{1, 2, 2, 3, 2};
a.remove(2);                    // 删除所有值为 2 的元素

a.remove_if([](int x) {        // 删除所有偶数
    return x % 2 == 0;
});
```

一边遍历一边删除时，必须接收 erase 返回的迭代器：

```cpp
for (auto it = a.begin(); it != a.end(); ) {
    if (*it % 2 == 0) {
        it = a.erase(it);       // it 已被删除，接收下一个有效位置
    } else {
        ++it;
    }
}
```

C++20：

```cpp
erase(a, 2);                     // 删除所有 2
erase_if(a, [](int x) {          // 删除所有偶数
    return x % 2 == 0;
});
```

---

## 9. 查找

```cpp
list<int> a{1, 3, 5, 7};

auto it = find(a.begin(), a.end(), 5);
if (it != a.end()) {
    cout << *it << '\\n';
}

auto it2 = find_if(a.begin(), a.end(), [](int x) {
    return x > 4;
});
```

find 和 find_if 都是 O(n)。

---

## 10. 排序 sort

```cpp
list<int> a{4, 1, 3, 2};

a.sort();                         // 升序：1 2 3 4
a.sort(greater<int>());           // 降序：4 3 2 1

a.sort([](int x, int y) {
    return abs(x) < abs(y);        // 按绝对值升序
});
```

list::sort 通常为 O(n log n)，且是稳定排序。

```cpp
// sort(a.begin(), a.end());      // 错误：std::sort 要求随机访问迭代器
```

结构体排序：

```cpp
struct Node {
    int id;
    int score;
};

list<Node> a{{1, 90}, {2, 80}, {3, 90}};
a.sort([](const Node& x, const Node& y) {
    if (x.score != y.score) return x.score > y.score;
    return x.id < y.id;
});
```

---

## 11. 去重 unique

unique 只删除相邻且相等的重复元素，不会自动删除所有重复值。

```cpp
list<int> a{1, 1, 2, 2, 2, 3, 1};
a.unique();                       // 1 2 3 1
```

想删除所有重复值，通常先排序再去重：

```cpp
list<int> a{3, 1, 2, 1, 3, 2};
a.sort();
a.unique();                       // 1 2 3
```

也可以自定义相邻元素的判断条件：

```cpp
a.unique([](int x, int y) {
    return x % 2 == y % 2;         // 奇偶性相同则视为重复
});
```

---

## 12. 反转 reverse

```cpp
list<int> a{1, 2, 3, 4};
a.reverse();                       // 4 3 2 1，O(n)
```

---

## 13. 合并 merge

merge 会把另一个链表的节点转移到当前链表中，并保持有序。两个链表必须按同一个规则排好序。

```cpp
list<int> a{1, 3, 5};
list<int> b{2, 4, 6};

a.merge(b);                       // a: 1 2 3 4 5 6，b: 空
```

降序合并：

```cpp
list<int> a{5, 3, 1};
list<int> b{6, 4, 2};
a.merge(b, greater<int>());        // a: 6 5 4 3 2 1
```

---

## 14. 节点转移 splice

splice 直接转移节点，不复制元素，也不重新分配节点。

```cpp
// 转移整个链表
list<int> a{1, 2};
list<int> b{3, 4};
a.splice(a.end(), b);              // a: 1 2 3 4，b: 空

// 转移一个节点
list<int> c{1, 2, 3};
list<int> d{10, 20};
auto pos = c.begin();
auto node = next(d.begin());       // 指向 20
c.splice(pos, d, node);             // c: 20 1 2 3，d: 10

// 转移一个区间 [first, last)
list<int> e{1, 2, 3};
list<int> f{10, 20, 30, 40};
auto first = next(f.begin(), 1);    // 20
auto last = next(f.begin(), 3);     // 40，尾后边界
e.splice(e.end(), f, first, last);  // e: 1 2 3 20 30
```

典型用途：移动任务节点、合并多个链表、在已知节点位置时 O(1) 地搬移节点。

---

## 15. 交换与赋值

```cpp
list<int> a{1, 2};
list<int> b{3, 4, 5};

a.swap(b);                         // a: 3 4 5，b: 1 2
swap(a, b);                        // 再交换回来

a = {7, 8, 9};
a.assign(3, 6);                    // a: 6 6 6
a.assign({1, 2, 3});
```

---

## 16. 常见复杂度

| 操作 | 复杂度 | 说明 |
| --- | --- | --- |
| front、back | O(1) | 访问首尾 |
| push_front、push_back | O(1) | 头尾插入 |
| pop_front、pop_back | O(1) | 头尾删除 |
| insert、erase | O(1) | 已知位置时，不包括寻找位置 |
| remove、remove_if | O(n) | 扫描并删除匹配元素 |
| find | O(n) | 无随机访问加速 |
| size | O(1) | 标准 C++ 中保证为常数复杂度 |
| sort | O(n log n) | list 的成员函数 |
| unique、reverse | O(n) | 扫描或反转节点链接 |
| merge | O(n + m) | 两个已排序链表合并 |
| splice | 通常 O(1) | 转移单个节点或整个链表 |

关键点：insert、erase 的 O(1) 不包括用 advance、find 找到位置的时间。

---

## 17. list 和 vector 怎么选

优先使用 vector 的情况：

- 需要下标随机访问。
- 主要在尾部插入和删除。
- 需要更好的缓存局部性和遍历速度。
- 需要使用 std::sort、二分查找等随机访问算法。

考虑使用 list 的情况：

- 已经持有迭代器，且需要频繁在中间插入或删除。
- 需要频繁移动节点，适合使用 splice。
- 不要求随机访问。
- 元素地址或迭代器需要在其他节点插入时保持稳定。

不要因为“链表插入是 O(1)”就默认选择 list。如果每次插入前都要从头遍历寻找位置，整体仍可能是 O(n^2)，而且 list 的缓存局部性通常比 vector 差。

---

## 18. 算法题常用模板

### 18.1 模拟双端队列

```cpp
list<int> q;
q.push_back(x);       // 从队尾加入
q.push_front(x);      // 从队头加入

if (!q.empty()) {
    int x = q.front();
    q.pop_front();    // 从队头取出
}
```

### 18.2 删除满足条件的节点

```cpp
for (auto it = a.begin(); it != a.end(); ) {
    if (bad(*it)) {
        it = a.erase(it);
    } else {
        ++it;
    }
}
```

### 18.3 先排序再去重

```cpp
a.sort();
a.unique();
```

### 18.4 把节点移动到另一个链表

```cpp
auto node = find(a.begin(), a.end(), value);
if (node != a.end()) {
    b.splice(b.end(), a, node);
}
```

---

## 19. 可运行总示例

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> a{4, 1, 3, 2, 2};

    a.push_front(0);
    a.push_back(5);
    a.sort();
    a.unique();

    for (auto it = a.begin(); it != a.end(); ) {
        if (*it % 2 == 0) {
            it = a.erase(it);
        } else {
            ++it;
        }
    }

    for (int x : a) cout << x << ' ';
    // 输出：1 3 5
}
```

## 20. 易错点总结

1. list 没有 [] 和 at()，不能随机访问。
2. std::sort(a.begin(), a.end()) 不适用于 list，应使用 a.sort()。
3. unique() 只删除相邻重复元素；想全局去重通常先 sort()。
4. erase(it) 后，it 失效，应使用 it = erase(it)。
5. front()、back()、pop_front()、pop_back() 前要确认链表非空。
6. merge() 要求两个链表都已按同一规则排序。
7. insert、erase 在已知迭代器位置时很快，但寻找位置仍可能需要 O(n)。
8. list 不是默认优于 vector；除非确实需要稳定迭代器、频繁中间增删或 splice，否则通常优先考虑 vector。
