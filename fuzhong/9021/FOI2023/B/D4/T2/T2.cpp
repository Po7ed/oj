#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f

int main()
{
	int n;
	scanf("%d",&n);
	ll a[n+1][2],e[n+1][n+1];
	fill(*e,*e+(n+1)*(n+1),INF);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a[i][0],&a[i][1]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				e[i][j]=abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
			}
		}
	}
	bool vis[n+1];
	fill(vis,vis+(n+1),false);
	// vis[1]=true;
	ll dis[n+1];
	fill(dis,dis+(n+1),INF);
	dis[1]=0;
	vector<int> mst[n+1];
	int pre[n+1];
	fill(pre,pre+(n+1),-1);
	ll cnt=0;
	int now=1;
	// for(int k=1;k<n;k++)
	while(!vis[now])
	{
		vis[now]=true;
		cnt+=dis[now];
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&dis[i]>e[i][now])
			{
				pre[i]=now;
				dis[i]=e[i][now];
			}
		}
		ll md=INF;
		int id;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&md>dis[i])
			{
				md=dis[i];
				now=i;
			}
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(pre[i]!=-1)
		{
			mst[pre[i]].push_back(i);
			// cnt+=e[pre[i]][i];
		}
	}
	// puts("prim over");
	#define dist(_i,_j) (abs(a[_i][0]-a[_j][0])+abs(a[_i][1]-a[_j][1]))
	vector<int> ans={1};
	auto dfs=[&ans,&a,&cnt,&mst]()->void
	{
		int last;
		auto dfs_=[&last,&ans,&a,&cnt,&mst](auto& self,int now,int pre)->void
		{
			if(now-1)
			{
				cnt+=(dist(ans.back(),now));
				// printf("%d:%d ",now,dist(ans.back(),now));
				ans.push_back(now);
				last=now;
			}
			// d.push_back(now);
			for(int to:mst[now])
			{
				self(self,to,now);
			}
			return;
		};
		dfs_(dfs_,1,1);
		cnt+=dist(last,1);
		printf("%lld\n",cnt);
		for(ll t:ans)
		{
			if(t-1)
			printf("%lld ",t);
		}
		return;
	};
	dfs();
	// printf("*\n%lld %lld %lld %lld %lld",dist(1,4),dist(4,3),dist(3,2),dist(2,5),dist(5,1));
	return 0;
}