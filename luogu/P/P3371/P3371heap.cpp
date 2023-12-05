#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct node
{
	int d,id;
};
bool operator < (node x,node y)
{
	return x.d>y.d;
}

int main()
{
	// freopen("P4779in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n,m,s;
	scanf("%d %d %d",&n,&m,&s);
	int /* a[n+1][n+1], */u,v,w;
	int head[n+1],to[m+1],val[m+1],nxt[m+1],tot=1;
	memset(head,0,sizeof(head));
	memset(to,0,sizeof(to));
	memset(val,0,sizeof(val));
	memset(nxt,0,sizeof(nxt));
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		to[tot]=v;
		val[tot]=w;
		nxt[tot]=head[u];
		head[u]=tot++;
	}
	int dis[n+1];
	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<node> q;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(t.d!=dis[t.id])
			continue;
		for(int i=head[t.id];i;i=nxt[i])
		{
			if(dis[to[i]]>dis[t.id]+val[i])
			{
				dis[to[i]]=dis[t.id]+val[i];
				q.push({dis[to[i]],to[i]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		// printf("%d ",(dis[i]==0x3f3f3f3f?-1:dis[i]));
		printf("%d ",(dis[i]==0x3f3f3f3f?0x7fffffff:dis[i]));
	}
	return 0;
}