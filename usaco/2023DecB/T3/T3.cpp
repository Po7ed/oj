#include <iostream>
#include <algorithm>
// #include <cmath>
using namespace std;
/*
 * 15:30 开题
 * ti 即排名
 * 妈妈生的
 * 先按排名排序 从大到小
 * 使得左小右大
 * 算出每个植物差后面那个植物多少（需要赶上）：dis=h(i+1)-hi
 * 并算出每个植物需要几天赶上：everyday=ai-a(i+1)
 * time=ceil(dis/everyday)
 * 由于不可能刚刚比他高，现在过了一会儿就被反超
 * 所以
 * 
 * 简单模拟题罢了（划掉）
 * 
 * 小心：多测不清空，亲人两行泪
 * 求天数
 * 16:04 答案真难捅
 * 不急，三三分类！
 * 16:22 分完了，码完了，测完了，交一发
 * 停！！！！！
 * long long！！！！！！！！！！
 * 16:24 交！
 * 2/13*100 pts
 * shit
 * shit
 * shit
 * 忘记 continue; 了
 * 16:28 交！
 * 10/13*100 pts
 * 海星。
 * 16:34 查出了
1 2
1 114
114 1
1 0
 * 无法通过（输出 -INF）
 * 将 ans1=0
 * 16:35 交！
 * 12/13*100 pts
 * genshin（doge）
 * 16:43 润
 */

typedef long long ll;
constexpr int N=214514;
struct p
{
	ll rk,h,v;
	friend inline bool operator < (p x,p y){return x.rk>y.rk;}
};
p a[N];
int T,n;
ll ans1,ans2;
ll d[N],e[N],t[N];

int main()
{
	// freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i].h);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i].v);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i].rk);
		if(n==1){puts("0");goto nextcase;}
		sort(a+1,a+n+1);
		ans1=0;
		ans2=0x3f3f3f3f3f3f3f3f;
		for(int i=2;i<=n;i++)
		{
			d[i]=a[i-1].h-a[i].h;
			e[i]=a[i].v-a[i-1].v;
			if(e[i]<=0&&d[i]>=0){puts("-1");goto nextcase;}
			if(e[i]<0&&d[i]<0){t[i]=d[i]/e[i];ans2=min(ans2,t[i]);continue;}
			if(e[i]==0&&d[i]<0){t[i]=0;}
			else t[i]=d[i]/e[i]+1;
			ans1=max(ans1,t[i]);
		}
		if(ans1>ans2)
		{
			puts("-1");
		}
		else
		{
			printf("%lld\n",ans1);
		}
		nextcase:;
	}
	return 0;
}