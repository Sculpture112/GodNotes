unsigned int ub = (unsigned int)b;
```cpp
这里一定要把b转为无符号，这样可以处理负数，也可以处理a和b同时为负数
```