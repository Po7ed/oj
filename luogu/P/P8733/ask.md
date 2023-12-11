在本题的第一篇题解中，是这么开数组的：
```cpp
const int M = 22;
int n; 
double D, x[M], y[M], d[M][M];
double f[1 << M][M]; // f[sta][i] sta 1/0 是/否访问城市，以 i 结束
```

其中 `f` 的大小明显为 $8\times22\times2^{22}\div 2^{20}=704\text{ MB}$。

本题空间限制 $256.00\text{ MB}$，但该题解的代码 AC 了。（[记录 1](https://www.luogu.com.cn/record/139110578)）。

***

我的代码：
```cpp
constexpr int N=21,M=1<<N;
int n;
double d;
double dis[N][N];
struct vi
{
	int x,y;
};
vi a[N];

double dp[M][N];
```

同样的，其中 `dp` 的大小应为 $8\times 21\times2^{21}\div 2^{20}=336\text{ MB}$。

当然，它 MLE 了。（[记录 2](https://www.luogu.com.cn/record/139108957)）。
将其中 `N=21` 改为 `N=20` 后，AC 了。（[记录 3](https://www.luogu.com.cn/record/139109514)）。

求问：

1. 为什么题解中的代码能 AC？
2. 为什么我的代码空间题解代码小但无法 AC？

***
附上完整代码：

题解：

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 22;
int n; 
double D, x[M], y[M], d[M][M];
double f[1 << M][M]; // f[sta][i] sta 1/0 是/否访问城市，以 i 结束

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            double dis = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            if (dis > D) d[i][j] = 1e18;
            else d[i][j] = dis;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int sta = 0; sta < (1 << n); sta++) {
        for (int i = 1; i <= n; i++) {
            f[sta][i] = 1e18;
        }
    }
    f[1][1] = 0;
}

signed main() {
    cin >> n >> D;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    init();
    for (int sta = 2; sta < (1 << n); sta++) {
        for (int i = 1; i <= n; i++) {
            if ((sta & (1 << (i - 1))) == 0) continue;
            for (int j = 1; j <= n; j++) {
                if (i == j || ((sta & (1 << (i - 1))) == 0)) continue;
                f[sta][i] = min(f[sta][i], f[sta ^ (1 << (i - 1))][j] + d[j][i]);   
            } 
        }
    }
    double ans = 1e18;
    for (int i = 1; i <= n; i++) ans = min(ans, f[(1 << n) - 1][i] + d[i][1]);
    printf ("%.3lf", ans);// 这里有个反抄袭
    return 0;
}
```

我的代码：
```cpp
#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

constexpr int N=22,M=1<<N;//! why
int n;
double d;
double dis[N][N];
struct vi
{
	int x,y;
};
vi a[N];

double dp[M][N];


int main()
{
	int td;
	scanf("%d %d",&n,&td);d=double(td);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		for(int j=0;j<i;j++)
		{
			dis[i][j]=dis[j][i]=sqrt(
			(a[i].x-a[j].x)*(a[i].x-a[j].x)+
			(a[i].y-a[j].y)*(a[i].y-a[j].y));
			if(dis[i][j]>d)dis[i][j]=dis[j][i]=1e9;
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	fill(*dp,*dp+M*N,1e9);
	dp[1][0]=0;
	for(int S=1;S<(1<<n);S++)
	{
		for(int i=0;i<n;i++)if((S>>i)&1)
		{
			// printf("%#x %d:%.2lf\n",S,i,dp[S][i]);
			for(int j=0;j<n;j++)if(i!=j&&!((S>>j)&1))// i->j
			{
				dp[S|(1<<j)][j]=min(dp[S|(1<<j)][j],dp[S][i]+dis[i][j]);
			}
		}
	}
	double ans=1e9;
	for(int i=0;i<n;i++)
	{
		ans=min(ans,dis[i][0]+dp[(1<<n)-1][i]);
	}
	printf("%.2lf",ans);
	return 0;
}
```