#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int n,m,k,s,t,u,v,w;
	scanf("%d %d %d\n%d %d",&n,&m,&k,&s,&t);
	int a[n][n];
	fill(a[0],a[0]+n*n,0x3f3f3f3f);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	int dis[n],p[n];
	bool vis[n];
	fill(vis,vis+n,false);
	// fill(p,p+n,-1);
	vis[s]=true;
	dis[s]=0;
	int d=0x3f3f3f3f,tt=-1;
	while(true)
	{
		for(int i=0;i<n;i++)
		{
			if(!vis[i]&&d>dis[i])
			{
				d=dis[i];
				tt=i;
			}
		}
		if(tt==-1)
			break;
		vis[tt]=true;
		for(int i=0;i<n;i++)
		{
			if(!vis[i]&&a[tt][i]!=0x3f3f3f3f&&dis[i]>dis[tt]+a[tt][i])
			{
				dis[i]=dis[tt]+a[tt][i];
				p[i]=tt;
			}
		}
	}
	priority_queue<int,vector<int>,less<int>> path;
	int i=t;
	while(i!=s)
	{
		path.push(a[p[i]][i]);
		i=p[i];
	}
	for(int j=0;j<k;j++)
		path.pop();
	int ans=0;
	/* for(int e:path)
	{
		ans+=e;
	} */
	while(!path.empty())
	{
		ans+=path.top();
		path.pop();
	}
	printf("%d",ans);
}