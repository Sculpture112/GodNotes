# [[0]]

> **原题链接:** (https://codeforces.com/gym/715305/problem/G)

**涉及知识点:** [[优化枚举]], [[模拟]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

**触发条件：**

**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// 将 x 镜像生成十进制回文。
// odd=true：末位不重复，例如 123 -> 12321
// odd=false：全部镜像，例如 123 -> 123321
int64 makePalindrome(int64 x, bool odd) {
    int64 result = x;

    if (odd) {
        x /= 10;
    }

    while (x > 0) {
        result = result * 10 + x % 10;
        x /= 10;
    }

    return result;
}

bool isPalindromeInBase(int64 x, int base) {
    int digit[64];
    int length = 0;

    while (x > 0) {
        digit[length++] = x % base;
        x /= base;
    }

    for (int left = 0, right = length - 1; left < right;
         ++left, --right) {
        if (digit[left] != digit[right]) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A;
    int64 N;
    cin >> A >> N;

    int64 answer = 0;

    for (int64 half = 1;; ++half) {
        int64 oddPalindrome = makePalindrome(half, true);
        int64 evenPalindrome = makePalindrome(half, false);

        if (oddPalindrome > N && evenPalindrome > N) {
            break;
        }

        if (oddPalindrome <= N &&
            isPalindromeInBase(oddPalindrome, A)) {
            answer += oddPalindrome;
        }

        if (evenPalindrome <= N &&
            isPalindromeInBase(evenPalindrome, A)) {
            answer += evenPalindrome;
        }
    }

    cout << answer << '\n';
    return 0;
}
```

---


