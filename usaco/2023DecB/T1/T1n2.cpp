#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
/*
 * 13:06 开题
 * 13:22 增加 min(ai,bj)-ai-1，<0:=0
 * 若一头牛比前面矮，必然长不高
 * 13:23 二分 a：bj。先码输入
 * 13:30 先打 O(n^2)
 * 13:37 单调队列？
 * 13:45 码完了
 * 13:46 挂了。只过了一个点，弱智
 * 13:47 弱智，没有每次算单调队列
 * 13:49 再交一发|tmd sb
 * 13:51 开新文件
 * cao 垃圾gdb
 * 14:00 14/20*100 pts,O(n^2)
 * 14:08 调出原码
 */
typedef long long ll;
constexpr int N=214514;
ll a[N],b[N];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=m;i++)scanf("%lld",b+i);
	ll th,tmp;
	for(int j=1;j<=m;j++)
	{
		th=0;
		for(int i=1;i<=n;i++)
		{
			tmp=min(a[i],b[j])-th;
			th=max(th,a[i]);
			a[i]+=(tmp>0?tmp:0);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld\n",a[i]);
	}
	return 0;
}