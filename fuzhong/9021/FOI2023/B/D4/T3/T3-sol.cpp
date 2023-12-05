#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct op
{
	int opt,x,y;
};

int main()
{
	//**********input**********
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v,w;
	int a[n+1][n+1],dis[n+1][n+1];
	bool del[n+1];
	memset(del,false,sizeof(del));
	memset(a,0x3f,sizeof(a));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		if(u!=v)
		a[u][v]=a[v][u]=dis[u][v]=dis[v][u]=w;
	}
	int q;
	scanf("%d",&q);
	int opt,x,y;
	vector<op> s;
	vector<int> ans;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&opt);
		if(opt-1)//SP
		{
			scanf("%d %d",&x,&y);
			s.push_back({opt,x,y});
		}
		else
		{
			scanf("%d",&x);
			s.push_back({opt,x,-1});
			del[x]=true;
		}
	}
	//**********floyd**********
	for(int k=n;k>0;k--)
	{
		if(del[k])
			continue;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	//**********do**********
	op t;
	while(!s.empty())
	{
		t=s.back();
		s.pop_back();
		if(t.opt-1)
		{
			ans.push_back(dis[t.x][t.y]);
		}
		else
		{
			//**********floyd(t.x only)**********
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					dis[i][j]=min(dis[i][j],dis[i][t.x]+dis[t.x][j]);
				}
			}
		}
	}
	/* for(int t:ans)
	{
		printf("%d\n",t);
	} */
	while(!ans.empty())
	{
		printf("%d\n",(ans.back()==0x3f3f3f3f?-1:ans.back()));
		ans.pop_back();
	}
	return 0;
}
