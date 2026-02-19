```cpp
我有一个长度为 l 的字符串，最开始时，这个字符串由 l 个句号（.）组成。我在这个字符串中，将多次把 boy 或者 girl 两单词，依次贴到这个字符串中。后贴上单词，会覆盖之前贴上的单词，或者覆盖句号。最终，每个单词至少有一个字符没有被覆盖。请问，一共贴有几个 boy 几个 girl？输入格式一行被反复贴有 boy 和 girl 两单词的字符串。输出格式两行，两个整数。第一行为 boy 的个数，第二行为 girl 的个数。输入输出样例输入 #1复制......boyogirlyy......girl.......
```

输出 #1复制

```cpp
4
2
```

说明/提示

数据保证，3≤l≤255，字符串仅仅包含如下字符：.bgilory。

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 基础设置
    string s;
    cin >> s;

    int cnt_boy = 0;
    int cnt_girl = 0;
    int len = s.length(); // 获取字符串长度，转为 int 防止无符号整数溢出

    // 1. 统计 boy 的个数
    // 我们遍历所有可能的 boy 起始位置。
    // boy 长度为 3，所以起始位置 i 最大只能到 len-3
    for (int i = 0; i <= len - 3; i++) {
        // 只要 b, o, y 中任意一个字符出现在了它应该出现的位置
        // 就说明这里贴过一个 boy
        if (s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y') {
            cnt_boy++;
        }
    }

    // 2. 统计 girl 的个数
    // girl 长度为 4，起始位置 i 最大只能到 len-4
    for (int i = 0; i <= len - 4; i++) {
        // 同理，只要 g, i, r, l 中任意一个字符对应上了
        // 就说明这里贴过一个 girl
        if (s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l') {
            cnt_girl++;
        }
    }

    // 输出结果
    cout << cnt_boy << endl;
    cout << cnt_girl << endl;

    return 0;
}
```