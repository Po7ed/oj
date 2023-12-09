#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr int N=214514;
int n,d;
struct edge
{
	int v,w,id;
};
vector<edge> e[N];

int dep[N],deg[N];
bitset<N> vis;
bool ring;
void dfs(int u,int f=0,int w=0)
{
	// printf("%d %d %d\n",u,f,w);
	if(vis[u]){ring=true;return;}
	vis[u]=true;
	dep[u]=dep[f]+w;
	for(edge to:e[u])if(to.v!=f&&d!=to.id)
	{
		dfs(to.v,u,to.w);
	}
}

int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%d",&n);
	int maxw=-0x3f3f3f3f,sumw=0;
	for(int i=1,u,v,w;i<=n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		deg[u]++;
		deg[v]++;
		e[u].push_back({v,w,i});
		e[v].push_back({u,w,i});
		maxw=max(maxw,w);
		sumw+=w;
	}
	bool isring=true;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]!=2)
		{
			isring=false;
		}
	}
	if(isring)
	{
		printf("%d",sumw-maxw);
		return 0;
	}
	int tmp,ans=0x3f3f3f3f;
	for(d=1;d<=n;d++)
	{
		ring=false;
		dfs(1);
		if(ring){vis.reset();goto con;}
		tmp=-1;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])goto con;
			vis[i]=false;
			if(tmp==-1||dep[tmp]<dep[i])
			{
				tmp=i;
			}
		}
		ring=false;
		dfs(tmp);
		if(ring){vis.reset();goto con;}
		tmp=-1;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])goto con;
			// vis[i]=false;
			tmp=max(tmp,dep[i]);
		}
		ans=min(ans,tmp);
		con:
		vis.reset();
	}
	printf("%d",ans);
	return 0;
}