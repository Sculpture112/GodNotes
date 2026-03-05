# 归并排序求小和（Small Sum）

```cpp
// 归并排序求小和（Small Sum）
const int MAXN = 100001;
int arr[MAXN], help[MAXN]; // 全局数组优化效率

// 核心逻辑：在合并过程中统计跨组的小和
long long merge(int l, int m, int r) {
    long long ans = 0;

    // 1. 统计阶段：利用有序性加速
    // 遍历右组的每个数 arr[j]，在左组找 <= arr[j] 的累加和
    long long current_sum = 0; 
    for (int j = m + 1, i = l; j <= r; j++) {
        // i 指针不回退：arr[j] 增大，满足条件的 arr[i] 范围只会向右扩大
        while (i <= m && arr[i] <= arr[j]) {
            current_sum += arr[i++];
        }注意上面的current_cum为此时j元素左边的总和，下面为ans的j元素是加上了上一个元素的总和，所以i指针不用回退，意思就是下一个j元素加上了上一个j元素的的总和，并且还要再加上它移动i指针产生的新总和
        ans += current_sum; // 当前右组元素 j 贡献的小和
    }

    // 2. 排序阶段：标准的归并逻辑
    int i = l, a = l, b = m + 1;
    while (a <= m && b <= r) {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= m) help[i++] = arr[a++];
    while (b <= r) help[i++] = arr[b++];

    // 3. 拷贝回原数组
    for (i = l; i <= r; i++) arr[i] = help[i];

    return ans;
}

// 递归入口
long long smallSum(int l, int r) {
    if (l == r) return 0;
    int m = l + ((r - l) >> 1);
    // 结果 = 左内部小和 + 右内部小和 + 跨左右产生的小和
    return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
}
```
