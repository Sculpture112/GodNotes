# Farmer John 有若干头奶牛。为了训练奶牛们的智力，

复制

输出：
> 1
复制

说明：
> MIAMI 位于州 FL，且 FLINT 的名称前两位字母为 FL；FLINT 位于州 MI，且 MIAMI 的名称前两位字母为 MI。其他城市不满足此条件，因此共有 1 对特殊城市。

```cpp
// Farmer John 有若干头奶牛。为了训练奶牛们的智力，他在谷仓的墙上放了一张美国地图。地图上标明了每个城市及其所在州的代码（前两位大写字母）。奶牛们注意到，如果城市 AA 的名称前两位字母等于城市 BB 所在州代码，且城市 BB 的名称前两位字母等于城市 AA 所在州代码，并且 A,BA,B 来自不同的州，则称 {A,B}{A,B} 是一对特殊城市。现有 NN 座城市，请你计算共有多少对特殊城市。输入描述：第一行输入一个整数 NN（1≦N≦2×1051≦N≦2×105），表示城市数量。接下来 NN 行，每行输入两个字符串：城市名称 SS（由 2∼102∼10 个大写字母组成）和所在州代码 CC（由 22 个大写字母组成），用空格隔开。保证同一州内城市名称互不相同。输出描述：输出一个整数，表示特殊城市对的数量。示例1输入：6
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> counts;
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        string cityName, stateCode;
        cin >> cityName >> stateCode;
        string cityCode = cityName.substr(0, 2);

        // 核心：只有当城市前两位和州代码不同时，才可能和“不同州”的城市配对
        if (cityCode != stateCode) {
            string target = stateCode + cityCode;
            if (counts.count(target)) {
                ans += counts[target];
            }
            // 记录当前组合
            counts[cityCode + stateCode]++;
        }
        // 如果 cityCode == stateCode，它永远无法满足“不同州”的配对要求，直接无视即可
    }

    cout << ans << endl;
    return 0;
}
```
