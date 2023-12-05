// tai_chou_xiang_la
#include <iostream>
//#include <vector>
//#include <cstdio>
using namespace std;

typedef long long ll;
const int N=114514;
int n,d;
int v[N],di[N],nxt[N];
ll dis[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d",&n,&d);
	for(int i=1;i<n;i++)
	{
		scanf("%d",di+i);
		dis[i+1]=dis[i]+1ll*di[i];
//		printf("dis[%d]=%d\n",i+1,dis[i+1]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",v+i);
	}
	int lst=1;
	for(int i=2;i<n;i++)
	{
		if(v[i]<v[lst])
		{
			nxt[lst]=i;
//			printf("nxt[%d]=%d\n",lst,i);
			lst=i;
		}
	}
	nxt[lst]=n;
	// oil: oils left can go dist
	ll tmp,oil=0,cost=0;
	for(int i=1;i<n;i=nxt[i])
	{
		tmp=(ll)(dis[nxt[i]])-(ll)dis[i]-oil;// dist
//		printf("%d to nxt need:%lld\n",i,tmp);
		oil=(d-tmp%d)%d;//dist/dpl=oil
//		printf("oil:%lld\n",oil);
//		printf("buy:%lld\n",(tmp%d?(tmp/d+1ll):(tmp/d)));
		cost+=(tmp%d?(tmp/d+1ll):(tmp/d))*v[i];
	}
	printf("%lld",cost);
	return 0;
}
