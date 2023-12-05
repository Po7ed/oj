#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a[11451],dep[11451],deg[11451];
vector<int> e[11451];
int ans;

int main()
{
	// freopen("P3074_2.in","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x].push_back(y);
		deg[y]++;
	}
    queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0)
		{
			dep[i]=a[i];
			q.push(i);
		}
	}
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		ans=max(ans,dep[u]);
		for(int v:e[u])
		{
			deg[v]--;
			dep[v]=max(dep[v],dep[u]+a[v]);
			if(deg[v]==0)
			{
				q.push(v);
			}
		}
	}
	printf("%d",ans);
	return 0;
}