```cpp
#include <bits/stdc++.h>
using namespace std;

int g[505][505];
void magicRotato(int x, int y, int r, int z) {
    // 1. 确定魔法影响的整块区域的四个极端边界
    int areaTop = x - r;
    int areaBottom = x + r;
    int areaLeft = y - r;
    int areaRight = y + r;

    // 2. 剥洋葱：从最外层往中心收缩（layer 决定当前在转哪一圈）
    for (int layer = 0; layer < r; layer++) {
        // 计算当前这一圈（层）的具体边界
        int currTop = areaTop + layer;
        int currBottom = areaBottom - layer;
        int currLeft = areaLeft + layer;
        int currRight = areaRight - layer;

        // 3. 偏移量 offset：在当前层的一条边上，我们要转动多少组“四个角”
        // 每一层的边长在缩短，所以 offset 的上限也在减小
        for (int offset = 0; offset < (currRight - currLeft); offset++) {

            if (z == 0) { // 顺时针旋转：左下 -> 左上 -> 右上 -> 右下 -> 左下
                int temp = g[currTop][currLeft + offset]; // 暂存左上

                // 核心：用坐标移动的方向来命名
                g[currTop][currLeft + offset] = g[currBottom - offset][currLeft];   // 左下 填到 左上
                g[currBottom - offset][currLeft] = g[currBottom][currRight - offset]; // 右下 填到 左下
                g[currBottom][currRight - offset] = g[currTop + offset][currRight];   // 右上 填到 右下
                g[currTop + offset][currRight] = temp;                                // 暂存的左上 填到 右上

            } else { // 逆时针旋转：右上 -> 左上 -> 左下 -> 右下 -> 右上
                int temp = g[currTop][currLeft + offset]; // 暂存左上

                g[currTop][currLeft + offset] = g[currTop + offset][currRight];    // 右上 填到 左上
                g[currTop + offset][currRight] = g[currBottom][currRight - offset]; // 右下 填到 右上
                g[currBottom][currRight - offset] = g[currBottom - offset][currLeft]; // 左下 填到 右下
                g[currBottom - offset][currLeft] = temp;                             // 暂存的左上 填到 左下
            }
        }
    }
}

int main(){
    int n,m;cin>>n>>m;
    int cnt = 1;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            g[i][j] = cnt++;
        }
    }

    while(m--){
        int x,y,r,z;
        cin>>x>>y>>r>>z;
        if(r==0) continue;
        magicRotato(x,y,r,z);
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<g[i][j]<<(j==n ?"":" ");
        }
        cout<<endl;
    }

}
```

```cpp

```

```cpp
# P4924 [1007] 魔法少女小Scarlet## 题目描述Scarlet 最近学会了一个数组魔法，她会在 $n\times n$ 二维数组上将一个奇数阶方阵按照顺时针或者逆时针旋转 $90^\circ$。首先，Scarlet 会把 $1$ 到 $n^2$ 的正整数按照从左往右，从上至下的顺序填入初始的二维数组中，然后她会施放一些简易的魔法。Scarlet 既不会什么分块特技，也不会什么 Splay 套 Splay，她现在提供给你她的魔法执行顺序，想让你来告诉她魔法按次执行完毕后的二维数组。## 输入格式第一行两个整数 $n,m$，表示方阵大小和魔法施放次数。接下来 $m$ 行，每行 $4$ 个整数 $x,y,r,z$，表示在这次魔法中，Scarlet 会把以第 $x$ 行第 $y$ 列为中心的 $2r+1$ 阶矩阵按照某种时针方向旋转，其中 $z=0$ 表示顺时针，$z=1$ 表示逆时针。## 输出格式输出 $n$ 行，每行 $n$ 个用空格隔开的数，表示最终所得的矩阵。## 输入输出样例 #1### 输入 #1```5 42 2 1 03 3 1 14 4 1 03 3 2 1```### 输出 #1```5 10 3 18 154 19 8 17 201 14 23 24 256 9 2 7 2211 12 13 16 21```## 说明/提示对于 $50\%$ 的数据，满足 $r=1$；对于 $100\%$ 的数据，满足 $1\leq n,m\leq500$，$1\leq x-r\leq x+r\leq n$，$1\leq y-r\leq y+r\leq n$。
```

```cpp

```