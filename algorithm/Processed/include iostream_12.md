# include <iostream>

```cpp
// 现代数学的著名证明之一是 Georg Cantor 证明了有理数是可枚举的。他是用下面这一张表来证明这一命题的：1/12/13/14/15/1​1/22/23/24/2⋯​1/32/33/3⋯​1/42/4⋯​1/5⋯⋯这次与 NOIp1999 第一题不同的是：这次需输入两个分数（不一定是最简分数），算出这两个分数的积（注意需要约分至最简分数），输出积在原表的第几列第几行（若积形如 a（即结果为整数）或者 1/a，则看作表内的 a/1 或 1/a 结算）。输入格式共两行。每行输入一个分数（不一定是最简分数）。输出格式两个整数，表示输入的两个分数的积在表中的第几列第几行。

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a1,a2,b1,b2;
    char spc;
    scanf("%d",&a1); spc  = getchar(); scanf("%d",&b1);
    scanf("%d",&a2); spc  = getchar(); scanf("%d",&b2);
    int c1 = a1 * a2,c2 = b2* b1;

    printf("%d %d\n",c2 / __gcd(c1,c2),c1 / __gcd(c1,c2));
    return 0;
}
```
