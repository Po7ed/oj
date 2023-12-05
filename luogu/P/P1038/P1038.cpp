#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// #define debug

struct edge
{
	int v,w;
};

int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	int c[n+1],b[n+1];
	vector<int> /* ip, */op;
	queue<int> q;
	int ipc=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&c[i],&b[i]);
		if(c[i])
		{
			// ip.push_back(i);
			ipc++;
			q.push(i);
		}
	}
	int u,v,w;
	vector<edge> e[n+1];
	int d1[n+1],d2[n+1];//1ru,2chu
	fill(d1,d1+(n+1),0);
	fill(d2,d2+(n+1),0);
	for(int i=0;i<p;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		d1[v]++;
		d2[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!d2[i])
		{
			op.push_back(i);
			// printf("op+%d\n",i);
		}
	}
	vector<int> topo;
	int t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		topo.push_back(t);
		for(edge to:e[t])
		{
			if(d1[to.v])
			{
				d1[to.v]--;
				if(!d1[to.v])
				{
					q.push(to.v);
				}
			}
		}
	}
	int sig[n+1];
	fill(sig,sig+(n+1),0);
	#ifdef debug
	for(int a:topo)
	{
		printf("%d ",a);
	}
	#endif
	int cnt=1;
	for(int a:topo)
	{
		if(cnt>ipc)
		{
			c[a]=sig[a]-b[a];
		}
		if(c[a]>=0)
		{
			for(edge ed:e[a])
			{
				sig[ed.v]+=(ed.w*c[a]);
			}
		}
		cnt++;
	}
	bool nul=true;
	for(int a:op)
	{
		if(c[a]>0)
		{
			nul=false;
			printf("%d %d\n",a,c[a]);
		}
	}
	if(nul)
	{
		puts("NULL");
	}
	return 0;
}