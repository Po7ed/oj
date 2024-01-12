#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int N=114514;
int n,m,c1,c2;
struct it
{
	int id,p;
	friend inline bool operator < (it x,it y){return x.p>y.p;}
};
it a1[N],a2[N];
int s1[N],s2[N];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,t,p;i<=n;i++)
	{
		scanf("%d %d",&t,&p);
		if(t==1)a1[++c1]={i,p};
		else a2[++c2]={i,p};
	}
	sort(a1+1,a1+c1+1);
	sort(a2+1,a2+c2+1);
	for(int i=1;i<=c1;i++)s1[i]=s1[i-1]+a1[i].p;
	for(int i=1;i<=c2;i++)s2[i]=s2[i-1]+a2[i].p;
	int ans=-1,w1,w2,j;
	for(int i=0;i<=c2&&i*2<=m;i++)// 2's num
	{
		j=min(c1,m-i*2);// 1's num
		if(ans<s2[i]+s1[j])
		{
			w1=j,w2=i;
			ans=s2[i]+s1[j];
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=w1;i++)printf("%d ",a1[i].id);
	for(int i=1;i<=w2;i++)printf("%d ",a2[i].id);
	return 0;
}