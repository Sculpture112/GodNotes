```cpp
# P5143 攀爬者## 题目背景HKE 考完 GDOI 之后跟他的神犇小伙伴们一起去爬山。## 题目描述HKE 在地形图上标记了 $N$ 个点，每个点 $P_i$ 都有一个坐标 $(x_i,y_i,z_i)$，且在所有点对中，高度值 $z$ 不会相等。HKE 准备从最低的点爬到最高的点，他的攀爬满足以下条件：1. 经过他标记的每一个点；2. 从第二个点开始，他经过的每一个点高度 $z$ 都比上一个点高；3. HKE 会飞，他从一个点 $P_i$ 爬到 $P_j$ 的距离为两个点的欧几里得距离，即 $\sqrt{(X_i-X_j)^2+(Y_i-Y_j)^2+(Z_i-Z_j)^2}$。现在，HKE 希望你能求出他攀爬的总距离。## 输入格式第一行，一个整数 $N$ 表示地图上的点数。接下来 $N$ 行，每行三个整数 $x_i,y_i,z_i$，表示第 $i$ 个点的坐标。## 输出格式一个实数，表示 HKE 需要攀爬的总距离（保留三位小数）。## 输入输出样例 #1### 输入 #1```52 2 21 1 14 4 43 3 35 5 5```### 输出 #1```6.928```## 说明/提示对于 $100\%$ 的数据，$1\leq N\leq 50000$，答案在 `double` 类型的表示范围内。
```

```cpp
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// const int N = ;
struct point {
    int x,y,z;
};

bool cmp(const point& a,const point& b){
    return a.z<b.z;
}

double getdis(const point& a,const point& b){
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y, 2) +pow(a.z - b.z,2));
}

void solve()
{
    int n;cin>>n;

    vector<point> points(n);
    for(int i = 0;i<n;i++){
        cin>> points[i].x >> points[i].y>>points[i].z;
    }

    sort(points.begin(),points.end(),cmp);

    double totaldis = 0.0;
    for(int i =0;i<n-1;++i){
        totaldis += getdis(points[i],points[i+1]);
    }

    cout<<fixed<<setprecision(3)<<totaldis<<endl;

}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
```