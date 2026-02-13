```cpp
// 038 Code07
```
```cpp
打印 n 层汉诺塔问题的最优移动轨迹
```
```cpp
// 核心思路：把 n 个盘子的移动拆解为三步
```
```cpp
// 1. 将前 n-1 个盘子从 from 移动到 other (利用 to 作为辅助)
```
```cpp
// 2. 将第 n 个盘子从 from 移动到 to
```
```cpp
// 3. 将前 n-1 个盘子从 other 移动到 to (利用 from 作为辅助)
```
#include