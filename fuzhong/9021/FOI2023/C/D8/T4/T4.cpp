#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int v,w;
};

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int u,v,w;
	vector<edge> e[n+1];
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	int dep[n+1],val[n+1];
	fill(dep,dep+(n+1),0);
	fill(val,val+(n+1),0);
	// dep[0]=0;
	// e[0].push_back({1,0});
	vector<pair<int,int>> dfs={make_pair(1,0)};
	int now,pre;
	int mul[n+1][11];
	fill(*mul,*mul+(n+1)*(11),0);
	while(!dfs.empty())
	{
		now=dfs.back().first;
		pre=dfs.back().second;
		dfs.pop_back();
		for(edge to:e[now])
		{
			if(to.v!=pre)
			{
				dfs.push_back({to.v,now});
				dep[to.v]=dep[now]+1;
				val[to.v]=val[now]+to.w;
				mul[to.v][0]=now;
			}
		}
	}
	for(int j=1;j<=10;j++)// 1 start
	{
		for(int i=1;i<=n;i++)
		{
			mul[i][j]=mul[mul[i][j-1]][j-1];
		}
	}
	int lca,uu,vv;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&u,&v);
		uu=u;
		vv=v;
		if(dep[uu]>dep[vv])
		{
			swap(uu,vv);
		}
		for(int j=10;j>=0;j--)
		{
			if(mul[vv][j]&&dep[mul[vv][j]]>=dep[uu])
			{
				vv=mul[vv][j];
			}
		}
		for(int j=10;j>=0;j--)
		{
			if(mul[uu][j]!=mul[vv][j])
			{
				uu=mul[uu][j];
				vv=mul[vv][j];
			}
		}
		if(uu!=vv)// uu==vv
		{
			lca=mul[uu][0];
		}
		else
		{
			lca=uu;
		}
		printf("%d\n",(val[u]+val[v]-2*val[lca]));
	}
	return 0;
}