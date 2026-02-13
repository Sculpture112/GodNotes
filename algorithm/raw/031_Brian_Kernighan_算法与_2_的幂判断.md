```cpp
// 031 Brian Kernighan 算法与 2 的幂判断
#include <iostream>

class Solution {
public:
    // 判断n是否为2的幂：逻辑是n必须大于0，且其二进制表示中只能有一个1
    bool isPowerOfTwo(int n) {
        // n & -n 可以提取出二进制最右侧的1。如果提取结果等于n，说明原数只有一个1
        return n > 0 && (long long)n == (n & -(long long)n); // 使用long long防止-INT_MIN溢出
```

```cpp
n & -n 的功能是“只提取最右侧的 1”。
```

```cpp
}
};
```