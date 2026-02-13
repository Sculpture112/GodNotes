return n > 0 && (long long)n == (n & -(long long)n); // 使用long long防止-INT_MIN溢出
```cpp
n & -n 的功能是“只提取最右侧的 1”。
```
    }