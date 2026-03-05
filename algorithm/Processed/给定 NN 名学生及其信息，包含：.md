# 给定 NN 名学生及其信息，包含：

```cpp
// 给定 NN 名学生及其信息，包含：
// ∙ ∙ 姓名 ss，仅含小写字母，长度不超过 88；
// ∙ ∙ 语文、数学、英语成绩 c1,c2,c3c1​,c2​,c3​，整数且 0≦ci≦1500≦ci​≦150。
定义总分 T=c1+c2+c3T=c1​+c2​+c3​，求总分最大的学生信息；若存在多名，取输入顺序最小者。

// 输入描述：
第一行包含整数 NN，(1≦N≦1000)(1≦N≦1000)；
// 接下来 NN 行，每行包含字符串 ss 和三个整数 c1,c2,c3c1​,c2​,c3​，依次表示学生姓名及三门成绩。

// 输出描述：
// 输出姓名 ss 及对应成绩 c1,c2,c3c1​,c2​,c3​，以空格分隔。

// 示例1

// 输入：
4
alice 100 90 80
david 90 100 80
mary 80 80 100
bob 100 90 80
// 复制

// 输出：
alice 100 90 80
// 复制

// 说明：

样例中，alice 与 bob 总分均为 270270，顺序提前者 alice 为答案。#include <iostream>
using namespace std;

struct Student {
    string name;
    int c1,c2,c3;
    int total;
};
int main() {
    int n;
    cin>>n;

    Student best;
    int maxTotal =-1;

    for(int i =0;i<n;i++){
        string currentName;
        int g1,g2,g3;
        cin>>currentName>>g1>>g2>>g3;

        int currentTotal = g1 +g2+g3;

        if(currentTotal>maxTotal){
            maxTotal = currentTotal;
            best.name = currentName;
            best.c1 = g1;
            best.c2 = g2;
            best.c3 = g3;
        }
    }
    cout<<best.name<<" "<<best.c1<<" "<<best.c2<<" "<<best.c3<<endl;

}
// 64 位输出请用 printf("%lld")
```
