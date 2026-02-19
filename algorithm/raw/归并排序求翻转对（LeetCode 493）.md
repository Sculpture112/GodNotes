```cpp
// 归并排序求翻转对（LeetCode 493）
```

```cpp
左加右再加跨左右
// 核心逻辑：在合并前统计 arr[i] > 2 * arr[j] 的数量
int merge(vector<int>& arr, int l, int m, int r) {
    // 1. 统计阶段：双指针不回退
    int ans = 0;
    // 对于左组的每个数 i，在右组找满足条件的 j 的边界
```

```cpp
先翻转判断，再排序
    for (int i = l, j = m + 1; i <= m; i++) {
        // 关键点：使用 long long 防止 arr[j] * 2 溢出
        while (j <= r && (long long)arr[i] > (long long)arr[j] * 2) {
            j++;
        }
        // j 停下的位置是第一个不满足条件的位置
        // 所以 [m+1 ... j-1] 都是满足条件的，数量为 j - (m + 1)
        ans += j - m - 1;
```

```cpp
右边的第一个是m+1，不满足的索引是j，左边满足的是j-1。所以ans+=j - m - 1;
```

```cpp
并且i没有移动，后续的i，肯定比之前的i大，所以i不用回退。
    }

    // 2. 排序阶段：标准归并
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
int counts(vector<int>& arr, int l, int r) {
    if (l == r) return 0;
    int m = l + ((r - l) >> 1);
    return counts(arr, l, m) + counts(arr, m + 1, r) + merge(arr, l, m, r);
}
```