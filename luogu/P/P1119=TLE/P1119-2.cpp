//You,a fvv.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int tof[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tof[i]);
	}
	int /* r[n][n], */ii,jj,vv;
	int dist[n][n];
	memset(dist,0x3f3f3f3f,sizeof(dist));
	// memset(r,0x3f3f3f3f,sizeof(r));
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&ii,&jj,&vv);
		// r[ii][jj]=vv;
		// r[jj][ii]=vv;
		dist[ii][jj]=dist[jj][ii]=vv;
	}
	int q;
	scanf("%d",&q);
	int u,v,t;
	int vis[n];
	fill(vis,vis+n,false);
	for(int l=0;l<q;l++)
	{
		scanf("%d %d %d",&u,&v,&t);
		/* for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(tof[j]<=t)
				{
					dist[i][j]=r[i][j];
				}
			}
		} */
		for(int k=0;k<n;k++)
		{
			if(tof[k]<=t&&!vis[k])
			{
				vis[k]=true;
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						/* if(dist[i][j]>dist[i][k]+dist[k][j])
						{
							dist[i][j]=dist[i][k]+dist[k][j];
						} */
						dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
					}
				}
			}
		}
		if(tof[u]>t||tof[v]>t||dist[u][v]==0x3f3f3f3f)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",dist[u][v]);
		}
	}
	return 0;
}