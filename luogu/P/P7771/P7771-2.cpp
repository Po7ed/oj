#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
int n,m;

struct edge
{
	int v,id;
	friend bool operator < (edge a,edge b)
	{
		return a.v<b.v;
	}
};

vector<edge> e[114514];
int ind[114514],outd[114514];
int cnt1,cnt2,s=1;

bitset<200008> vis;
int order[114514],top=1;
void dfs(int now=s)
{
	printf("now:%d\n",now);
	for(edge to:e[now])
	{
		if(!vis[to.id])
		{
			vis[to.id]=true;
			dfs(to.v);
		}
	}
	// printf("now:%d\n",now);
	order[top++]=now;
}
int main()
{
	vis.reset();
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back({v,i});
		outd[u]++;
		ind[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(ind[i]!=outd[i])
		{
			if(ind[i]==outd[i]-1)
			{
				s=i;
				cnt1++;
			}
			else if(outd[i]==ind[i]-1)
			{
				cnt2++;
			}
			else
			{
				puts("No");
				return 0;
			}
		}
	}
	if(!((cnt1==0&&cnt2==0)||(cnt1==1&&cnt2==1)))
	{
		puts("No");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sort(e[i].begin(),e[i].end());
	}
	dfs();
	for(int i=top-1;i;i--)
	{
		printf("%d ",order[i]);
	}
	return 0;
}