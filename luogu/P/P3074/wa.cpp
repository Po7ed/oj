#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a[11451],dep[11451],deg[11451];
vector<int> e[11451];

int main()
{
	// freopen("P3074_2.in","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int uu,vv;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&uu,&vv);
		e[uu].push_back(vv);
		deg[vv]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!deg[i])
		{
			q.push(i);
			dep[i]=a[i];
		}
	}
	int u,ans=-1;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int v:e[u])
		{
			deg[v]--;
			dep[v]=max(dep[v],dep[u]+a[v]);
			if(!deg[v])
			{
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dep[u]);//u->v
	}
	printf("%d",ans);
	return 0;
}