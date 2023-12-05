#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dep[114514],deg[114514];
vector<int> e[114514];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,vv;
	queue<int> q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&vv);
		e[u].push_back(vv);
		deg[vv]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!deg[i])
		{
			q.push(i);
			dep[i]=1;
		}
	}
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int v:e[u])
		{
			deg[v]--;
			if(!deg[v])
			{
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",dep[i]);
	}
	return 0;
}