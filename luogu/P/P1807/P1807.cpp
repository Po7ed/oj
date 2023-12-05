#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
	int v,w;
};

const int N=2145;
int n,m;
int deg[N],dp[N];
vector<edge> e[N];
vector<int> tp;

int main()
{
	scanf("%d %d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		deg[v]++;
		e[u].push_back({v,w});
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!deg[i])
		{
			q.push(i);
		}
	}
	int t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(!(tp.empty()&&t!=1))
		{
			tp.push_back(t);
		}
		for(edge to:e[t])
		{
			deg[to.v]--;
			if(!deg[to.v])
			{
				q.push(to.v);
			}
		}
	}
	fill(dp,dp+N,-0x3f3f3f3f);
	dp[1]=0;
	for(int i:tp)
	{
		for(edge to:e[i])
		{
			dp[to.v]=max(dp[to.v],dp[i]+to.w);
		}
	}
	printf("%d",(dp[n]==-0x3f3f3f3f?-1:dp[n]));
	return 0;
}