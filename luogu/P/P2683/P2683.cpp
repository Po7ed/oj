#include <iostream>
#include <queue>
using namespace std;

struct ndfp
{
	int id,d;
	friend bool operator < (ndfp a,ndfp b)
	{
		return a.d<b.d;
	}
};

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int s,tt,u,v,w,op;
	int a[n+1][n+1];
	fill(*a,*a+(n+1)*(n+1),0x3f3f3f3f);
	priority_queue<ndfp> q;
	ndfp t;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&op);
		if(op)
		{
			scanf("%d %d %d",&u,&v,&w);
			a[u][v]=a[v][u]=min(w,a[u][v]);
		}
		else
		{
			scanf("%d %d",&s,&tt);
			int dis[n+1];
			fill(dis,dis+(n+1),0x3f3f3f3f);
			dis[s]=0;
			q.push({s,0});
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
					if(dis[i]>t.d+a[t.id][i])
					{
						dis[i]=t.d+a[t.id][i];
						q.push({i,dis[i]});
					}
				}
			}
			printf("%d\n",(dis[tt]==0x3f3f3f3f?-1:dis[tt]));
		}
	}
}