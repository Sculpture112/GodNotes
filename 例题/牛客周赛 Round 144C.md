# []

> **原题链接:** (https://ac.nowcoder.com/acm/contest/134957/C)

**涉及知识点:** [[高精度]], [[]]，[[需重刷]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 通用高精度减法：假设 num1 >= num2
string subtract_strings(string num1, string num2) {
    string res = "";
    int borrow = 0;
    int p1 = num1.size() - 1, p2 = num2.size() - 1;
    
    while (p1 >= 0 || p2 >= 0) {
        int d1 = p1 >= 0 ? num1[p1] - '0' : 0;
        int d2 = p2 >= 0 ? num2[p2] - '0' : 0;
        
        int diff = d1 - d2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(diff + '0');
        p1--; p2--;
    }
    
    // 去除前导 0
    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve_simulation() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    if (n > m) swap(n, m);
    
    if (n == m) {
        cout << "0 ";
        // 最大差值 = 99..9 - 10..0
        string max_n(n, '9');
        string min_n = "1" + string(n - 1, '0');
        cout << subtract_strings(max_n, min_n) << "\n";
    } else {
        // 较小数的边界
        string min_n = "1" + string(n - 1, '0');
        string max_n(n, '9');
        
        // 较大数的边界
        string min_m = "1" + string(m - 1, '0');
        string max_m(m, '9');
        
        // 最小差值：较大数尽量小，较小数尽量大
        string min_diff = subtract_strings(min_m, max_n);
        // 最大差值：较大数尽量大，较小数尽量小
        string max_diff = subtract_strings(max_m, min_n);
        
        cout << min_diff << " " << max_diff << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve_simulation();
    return 0;
}
```

---


