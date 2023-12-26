#include <iostream>
#include <cmath>
using namespace std;

/*
 * 14:10 开题
 * 求最少最初的感染数
 * 14:16 一个连通块（1）的半径即为最长传播时间
 * 对于每个连通块，传播时间：[0,半径长度] 例如：
 * 111：[0,1] 晚
 * 1111：[0,1] 晚
 * 对于每个连通块求出区间 [0,rj]
 * 统计 min{rj} 例如：
 * [    ]
 * [ ] <--- 传染时间最短
 * [      ]
 * 传染时间最大值的最小值——二分答案？
 * 使时间尽可能大。（有些达不到那么大，所以取最小）
 * 最初尽可能少牛——YES！
 * 14:23 开码
 * 14:33 通过最短时间算初始
 * 但是会不会 010010->111111
 * 11111110111111
 * 1111101111
 * 要求最少发病头数……
 * 并不要求快！！！
 * 每个连通块……
 * ***
 * 首先传播时间肯定要长，开始数才会小——YES
 * mimat 肯定是对的——YES
 * 14:42 急
 * 难点在于如何通过 最短时间算初始 使他最小
 * 考虑贪心
 * 已知最短时间，必然不希望重合（重复）感染
 * 填充最小初始例子：找规律
 * x:1
 * xx:2
 * 1x1:1
 * 1xx1:2
 * 1x1x1:2
 * 1x11x1:2
 * 1111111:2
 * 呸！
 * 已知时间 t，1->111->11111（2*t+1）个
 * 11->1111->111111（2*t+2）个
 * 奇偶分别考虑
 * t=2: 5/6
 * t=3: 7/8
 * 上取整！
 * 优先填 2*t+1
 * 第二种 2*t+2 废！！！
 * 14:52 开码
 * 14:56 码完
 * 妈妈生的
 * 哦！
 * 退出统计连通块时要结束最后一个连通块
 * 妈妈生的
 * 调完
 * 15:00 交一发，7/12*100 pts，O(n)
 * 妈妈生的
 * 查错
 * 15:11 查不出来
 * 15:17 边界？
 * 似乎是的
 * 两个边界的最长传播时间为 a[i] 本身！！！！！
 * 15:20 再交一发！
 * 8/12*100 pts，O(n)
 * 15:22 但是，没改完整！
 * 我是弱智
 * 15:28 再交一发！！
 * 11/12*100 pts O(n)
 * 润！
 * 17:02 交
 * CE 吓死
 * 17:04 交，还是 WA，润。
 */
constexpr int N=314514;
int n,cnt;
char s[N];
int a[N],mat[N],beg[N];//^ 连通块长度；最长传播晚数，最小开始牛数

int main()
{
	scanf("%d\n%s",&n,s+1);
	int tmp=0;
	for(int i=1;i<=n;i++)//^ 统计连通块长度
	{
		if(s[i]=='0'&&tmp)a[++cnt]=tmp,tmp=0;
		else if(s[i]=='1')tmp++;
	}
	if(tmp)a[++cnt]=tmp;//! this
	int mimat=0x7fffffff,d;//! this:0x3f...
	for(int i=2;i<cnt;i++)
	{
		mat[i]=(a[i]-1)>>1;//^ calc
		mimat=min(mimat,mat[i]);//^ get
	}
	mimat=min(mimat,min(a[1],a[cnt])-1);
	d=mimat<<1|1;//^ calc d
	int ans=0;
	for(int i=1;i<=cnt;i++)//todo min time how to calc
	{//! no mat[i]
		beg[i]=a[i]/d+int(bool(a[i]%d));
		// if(beg[i]==0)while(1);
		ans+=beg[i];
	}
	printf("%d",ans);
	// printf("\n%d",d);//todo remember comment this
	return 0;
}