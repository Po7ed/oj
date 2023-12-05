#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int v,id;
};

vector<edge> del;
vector<edge> e[200001];


int dfs(int now,int pre)
{
	int siz=1;
	edge tofa;
	for(edge to:e[now])
	{
		if(to.v!=pre)
		{
			siz+=dfs(to.v,now);//累加返回值。
		}
		else
		{
			tofa=to;
		}
	}
	/* if(pre==-1&&siz!=3)
	{
		// printf("siz:%d\n",siz);
		return siz;
	} */
	if(siz==3)
	{
		if(pre!=-1)
		{
			del.push_back(tofa);
		}
		return 0;
	}
	else if(siz<3)
	{
		return siz;
	}
	else
	{
		// puts("-1");
		return 0x3f3f3f3f;
	}
	return 114514;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		del.clear();
		// fill(vtoid,vtoid+n+1,0);
		int n;
		scanf("%d",&n);
		int u,v;
		if(n%3)
		{
			puts("-1");
			for(int i=1;i<n;i++)
			{
				scanf("%d %d",&u,&v);
			}
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			e[u].push_back({v,i});
			e[v].push_back({u,i});
		}
		if(!dfs(1,-1))
		{
			printf("%d\n",del.size());
			for(edge d:del)
			{
				printf("%d ",d.id);
			}
			puts("");
		}
		else
		{
			puts("-1");
		}
	}
	return 0;
}
