#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long 龙龙;
const 龙龙 mod=80112002;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v,d[n+1],d_[n+1];// v eat u,rudu
	fill(d,d+(n+1),0);
	fill(d_,d_+(n+1),0);
	vector<int> e[n+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		d[v]++;
		d_[u]++;
	}
	queue<int> q;
	龙龙 dp[n+1];
	fill(dp,dp+(n+1),0);
	for(int i=1;i<=n;i++)
	{
		if(!d[i])
		{
			q.push(i);
			dp[i]=1;
		}
	}
	vector<int> topo;
	int t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		topo.push_back(t);
		for(int to:e[t])
		{
			d[to]--;
			if(!d[to])
			{
				q.push(to);
			}
		}
	}
	for(int i:topo)
	{
		for(int to:e[i])
		{
			dp[to]+=dp[i];
			dp[to]%=mod;
		}
	}
	龙龙 cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!d_[i])
		{
			cnt+=dp[i];
			cnt%=mod;
		}
	}
	printf("%lld",cnt);
	return 0;
}