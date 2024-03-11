#include <iostream>
#include <algorithm>
#include <bitset>

constexpr int N=5114,INF=0x3f3f3f3f;
int n,m,aa,b,c,d,p;
typedef long long ll;

int a[N*N];
int e[N][N],e_[N][N];
int dis[N],dis_[N];
std::bitset<N> vis,vis_;

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d %d %d %d %d %d %d",&n,&m,&aa,&b,&c,&d,&p);
	a[0]=aa;
	for(int i=1,k;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			k=(i-1)*m+j;
			a[k]=(1ll*b*a[k-1]*a[k-1]+1ll*c*a[k-1]+1ll*d)%p;
			e[i][j]=e_[j][i]=a[k];
			// printf("%d ",a[k]);
		}
		// puts("");
	}
	std::fill(dis,dis+n+1,INF);
	std::fill(dis_,dis_+m+1,INF);
	dis[1]=0;
	ll ans=0;
	for(int i=1,u,u_;i<=n+m;i++)
	{
		u=u_=0;
		for(int j=1;j<=n;j++)if(dis[u]>dis[j]&&!vis[j])u=j;
		for(int j=1;j<=m;j++)if(dis_[u_]>dis_[j]&&!vis_[j])u_=j;
		if(dis[u]<dis_[u_])
		{
			ans+=dis[u];
			// printf("%d\n",dis[u]);
			for(int v=1;v<=m;v++)dis_[v]=std::min(dis_[v],e[u][v]);
			// dis[u]=INF;
			vis[u]=true;
			// printf("i:%d\n",u);
		}
		else
		{
			ans+=dis_[u_];
			// printf("%d_\n",dis_[u_]);
			for(int v=1;v<=n;v++)dis[v]=std::min(dis[v],e_[u_][v]);
			// dis_[u_]=INF;
			vis_[u_]=true;
			// printf("j:%d\n",u_);
		}
		// printf("dis:");
		// for(int j=1;j<=n;j++)printf("%d ",dis[j]);
		// printf("\ndis_:");
		// for(int j=1;j<=m;j++)printf("%d ",dis_[j]);
		// puts("");
	}
	printf("%lld",ans);
	return 0;
}