# []

> **原题链接:** (https://www.luogu.com.cn/problem/P1177)

**涉及知识点:** [[]], [[]]，[[需重刷]]

**难度 [[]]


```cpp
// 025 Code01 堆结构和堆排序，acm练习风格

// 测试链接 : https://www.luogu.com.cn/problem/P1177
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// C++ 提交时直接全部复制提交即可通过

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

// 全局静态数组，避免动态分配开销
int arr[MAXN];
int n;

// i位置的数，向上调整大根堆
void heapInsert(int i) {
    while (arr[i] > arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// i位置的数，向下调整大根堆
// 当前堆的大小为size
void heapify(int i, int size) {
    int l = i * 2 + 1;
    while (l < size) {
        // 找出左右孩子中较大的那个
        int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
        // 找出孩子和父节点中较大的那个
        best = arr[best] > arr[i] ? best : i;
        if (best == i) {
            break;
        }
        swap(arr[best], arr[i]);
        i = best;
        l = i * 2 + 1;
    }
}

// 从顶到底建立大根堆，O(n * logn)
// 依次弹出堆内最大值并排好序，O(n * logn)
// 整体时间复杂度O(n * logn)
void heapSort1() {
    for (int i = 0; i < n; i++) {
        heapInsert(i);
    }
    int size = n;
    while (size > 1) {
        swap(arr[0], arr[--size]);
        heapify(0, size);
    }
}

// 从底到顶建立大根堆，O(n)
// 依次弹出堆内最大值并排好序，O(n * logn)
// 整体时间复杂度O(n * logn)
void heapSort2() {
    for (int i = n - 1; i >= 0; i--) {
        heapify(i, n);
    }
    int size = n;
    while (size > 1) {
        swap(arr[0], arr[--size]);
        heapify(0, size);
    }
}

int main() {
    // C++ 的快速 I/O 模板，极大提升读写效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 持续读取直到文件结束
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // heapSort1();
        heapSort2();
        
        // 格式化输出，最后一个元素后不带空格，带换行
        for (int i = 0; i < n - 1; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[n - 1] << "\n";
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
