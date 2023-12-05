#include <iostream>
using namespace std;

typedef long long ll;
const int N=114;
int n;
ll q;
ll e[N][N],mi[N][N],dis[N][N],disum,md[N][N],maxdiff=-1,te[N][N];

inline void Floyd(ll g[N][N],ll d[N][N])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=g[i][j];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
inline ll getsum(ll d[N][N])
{
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			res+=d[i][j];
		}
	}
	return res;
}
bool check(int x)
{
	int rnd=(x-1)/n,end=(x-1)%n+1,tmp;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			te[i][j]=e[i][j];
		}
	}
	for(int now=1;now<=n;now++)
	{
		tmp=rnd+(now<=end);
		for(int to=1;to<=n;to++)
		{
			te[now][to]=max(te[now][to]-tmp,mi[now][to]);
			te[to][now]=te[now][to];
		}
	}
	Floyd(te,dis);
	disum=getsum(dis);
	return disum<=q;
}

int main()
{
	scanf("%d %lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&e[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&mi[i][j]);
			maxdiff=max(maxdiff,e[i][j]-mi[i][j]);
		}
	}
	Floyd(mi,md);
	ll sum=getsum(md);
	if(sum>q)
	{
		puts("-1");
		return 0;
	}
	Floyd(e,dis);
	sum=getsum(dis);
	if(sum<=q)
	{
		puts("0");
		return 0;
	}
	int l=0,r=n*(maxdiff+1),mid,ans=0x3f;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%d",ans);
	return 0;
}