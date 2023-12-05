#include <iostream>
#include <queue>
#include <bitset>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v,tot=1,to[m*2+1],nxt[m*2+1],head[n+1];
	fill(head,head+n+1,0);
	fill(to,to+2*m+1,-1);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		if(u==v)
			continue;
		to[tot]=v;
		nxt[tot]=head[u];
		head[u]=tot++;
		to[tot]=u;
		nxt[tot]=head[v];
		head[v]=tot++;
	}
	int ans[n+1],dep[n+1];
	// bool vis[n+1];
	// const size_t s=n+1;
	bitset<1000001> vis;
	vis.reset();
	fill(ans,ans+n+1,0);
	fill(dep,dep+n+1,0);
	// fill(vis,vis+n+1,false);
	ans[1]=1;
	vis[1]=true;
	queue<int> q;
	q.push(1);
	int l,t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(int i=head[t];i;i=nxt[i])
		{
			if(!vis[to[i]])
			{
				vis[to[i]]=true;
				dep[to[i]]=dep[t]+1;
				// ans[to[i]]++;
				q.push(to[i]);
			}
			if(dep[to[i]]==dep[t]+1)
			{
				ans[to[i]]=(ans[to[i]]+ans[t])%100003;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
/* 
4 4
1 2
2 3
3 4
4 1
 */