#include <iostream>
#include <vector>
using namespace std;
int m,n=-1;
int e[501][501];
vector<int> r;
void dfs(int now)
{
	for(int i=1;i<=n;i++)
	{
		if(e[now][i])
		{
			e[now][i]--;
			e[i][now]--;
			dfs(i);
		}
	}
	r.push_back(now);
	return;
}

int main()
{
	scanf("%d",&m);
	int u,v;
	int d[501];
	fill(d,d+501,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		n=max(n,max(u,v));
		e[u][v]++;
		e[v][u]++;
		d[u]^=1;
		d[v]^=1;
	}
	int start=1;
	for(int i=1;i<=n;i++)
	{
		if(d[i])
		{
			start=i;
			break;
		}
	}
	dfs(start);
	while(!r.empty())
	{
		printf("%d\n",r.back());
		r.pop_back();
	}
	return 0;
}