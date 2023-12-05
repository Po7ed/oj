#include <iostream>
#include <vector>
#include <cstring>
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
//	memset(del,false,sizeof(del));
	for(int i=1;i<=n;i++)
	{
		del[i]=false;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=dis[i][j]=0x3f3f3f3f;
		}
	}
//	memset(*a,0x3f3f3f3f,sizeof(a));
//	memset(*dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=a[v][u]=dis[u][v]=dis[v][u]=w;
		// a[u][v]=a[v][u]=min(w,a[u][v]);
		// dis[u][v]=dis[v][u]=min(w,dis[u][v]);
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
	for(int k=1;k<=n;k++)
	{
		if(del[k])
			continue;
		// printf("k=%d\n",k);
		for(int i=1;i<=n;i++)
		{
			if(del[i])
				continue;
			for(int j=1;j<=n;j++)
			{
				if(del[j])
					continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				// printf("%c(%d,%d)=%d ","-!"[(dis[i][j]==dis[i][k]+dis[k][j])],i,j,dis[i][j]==0x3f3f3f3f?-1:dis[i][j]);				
			}
			// puts("");
		}
		// puts("");
	}
	// puts("");
	//**********do**********
	// for(op t:s)
	op t;
	while(!s.empty())
	{
		t=s.back();
		s.pop_back();
		if(t.opt-1)
		{
//			printf("%d\n",dis[t.x][t.y]);
			ans.push_back(dis[t.x][t.y]);
		}
		else
		{
			// printf("plus:%d\n",t.x);
			del[t.x]=false;
			//**********floyd(t.x only)**********
			// for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
			{
				if(del[i])
					continue;
				for(int j=1;j<=n;j++)
				{
					if(del[j])
						continue;
					dis[i][j]=min(dis[i][j],dis[i][t.x]+dis[t.x][j]);
					// printf("(%d,%d)=%d ",i,j,dis[i][j]==0x3f3f3f3f?-1:dis[i][j]);				
//					printf("(%d,%d):%d ",i,j,dis[i][j]);
				}
				// puts("");
			}
		}
	}
//	for(int t:ans)
//	{
//		printf("%d\n",t);
//	}
	while(!ans.empty())
	{
		printf("%d\n",(ans.back()==0x3f3f3f3f?-1:ans.back()));
		ans.pop_back();
	}
	return 0;
}
