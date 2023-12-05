#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N=214514,M=414514;
int n,m;
int l[N],r[N],id[M],opt[M],ans[N];
bitset<N> ban[2];

int now;
bitset<N> vis;
void still(int u=1)
{
	if(vis[u])
	{
		return;
	}
	vis[u]=true;
	ans[u]=now;
	if(!ban[0][u])
	{
		still(l[u]);
	}
	if(!ban[1][u])
	{
		still(r[u]);
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",l+i,r+i);
		if(l[i]==-1)
		{
			ban[0][i]=true;
		}
		if(r[i]==-1)
		{
			ban[1][i]=true;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",id+i,opt+i);
		ban[--opt[i]][id[i]]=true;
	}
	now=-1;
	still();
	for(int i=m;i;i--)
	{
		now=i-1;
		ban[opt[i]][id[i]]=false;
		printf("%d %d\n",id[i],opt[i]);
		if(!opt[i])
		{
			if(vis[id[i]]&&!vis[l[id[i]]])
			{
				still(l[id[i]]);
			}
			else if(!vis[id[i]]&&vis[l[id[i]]])
			{
				still(id[i]);
			}
		}
		else
		{
			if(vis[id[i]]&&!vis[r[id[i]]])
			{
				still(r[id[i]]);
			}
			else if(!vis[id[i]]&&vis[r[id[i]]])
			{
				still(id[i]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",(!vis[i]?-1:ans[i]));
	}
	return 0;
}