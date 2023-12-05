#include <iostream>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

struct ndfp
{
	int d,id;
	friend bool operator < (ndfp a,ndfp b)
	{
		return a.d<b.d;
	}
};

int main()
{
	int n,m;
	scanf("%d\n%d",&n,&m);
	int u,v,w;
	int a[n+1][n+1];
	int b[n+1][n+1];
	fill(*a,*a+(n+1)*(n+1),INF);
	fill(*b,*b+(n+1)*(n+1),0);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=a[v][u]=w;
	}
	int d;
	scanf("%d",&d);
	for(int i=0;i<d;i++)
	{
		scanf("%d %d",&u,&v);
		b[u][v]=b[v][u]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==INF)
			{
				continue;
			}
			a[i][j]=a[i][j]*b[i][j];
		}
	}
	int A,B;//a->b
	scanf("%d %d",&A,&B);
	priority_queue<ndfp> q;
	q.push({0,A});
	ndfp t;
	int dis[n+1];
	fill(dis,dis+(n+1),INF);
	dis[A]=0;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(dis[t.id]!=t.d)
		{
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(dis[i]>t.d+a[i][t.id])
			{
				dis[i]=t.d+a[i][t.id];
				q.push({dis[i],i});
			}
		}
	}
	printf("%d",dis[B]);
	return 0;
}