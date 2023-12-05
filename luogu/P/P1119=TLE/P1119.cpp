#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int tof[n];//time of [i]
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tof[i]);
	}
	int r[n][n],ii,jj,vv;
	memset(r,0x3f3f3f3f,sizeof(r));
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&ii,&jj,&vv);
		r[ii][jj]=vv;
		r[jj][ii]=vv;
	}
	int q;
	scanf("%d",&q);
	int u,v,t;
	for(int l=0;l<q;l++)
	{
		scanf("%d %d %d",&u,&v,&t);
		int dist[n]/* [n] */;
		bool vis[n];
		fill(vis,vis+n,false);
		// memset(dist,0x3f3f3f3f,sizeof(dist));
		fill(dist,dist+n,0x3f3f3f3f);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(tof[j]<=t)
				{
					dist/* [i] */[j]=r[u][j];
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(tof[i]>t)
			{
				vis[i]=true;
			}
		}
		dist[u]=0;
		vis[u]=true;
		//Dijkstra
		// while(true)
		/* for(int k=0;k<n;k++)
		{
			int mind=0x3f3f3f3f,t=-1;
			for(int i=0;i<n;i++)
			{
				if(!vis[i]&&mind>dist[i])
				{
					t=i;
					mind=dist[i];
				}
			}
			if(t==-1)
			{
				// puts("-1");
				// goto bre;
				break;
			}
			vis[t]=true;
			for(int i=0;i<n;i++)
			{
				if(dist[t]+r[t][i]<dist[i]&&!vis[i]&&tof[])
				{
					dist[i]=dist[t]+r[t][i];
				}
			}
		} */
		//Floyd O(n^3)
		/* for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(dist[i][j]>dist[i][k]+dist[k][j])
					{
        				dist[i][j]=dist[i][k]+dist[k][j];
					}
				}
			}
		} */
		if(dist/* [u] */[v]==0x3f3f3f3f||tof[u]>t||tof[v]>t)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",dist/* [u] */[v]);
		}
		// bre:;
	}
	return 0;
}