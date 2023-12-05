#include <iostream>
#include <vector>
using namespace std;

int d=-1;
vector<int> e[114514];

void dfs(int now=1,int pre=0,int dep=0)
{d=max(d,dep);for(int to:e[now])if(to!=pre)dfs(to,now,dep+1);return;}

int main()
{
	int n;
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs();
	// printf("d:%d\n",d);
	for(int k=1;k<=n;k++)
	{
		printf("%d\n",2*k-2-min(k-1,d));
	}
	return 0;
}