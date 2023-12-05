#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int a[6114],dp[6114][2];
bitset<6114> nrt;
vector<int> e[6114];

void dfs(int u)
{
	dp[u][1]=a[u];
	for(int v:e[u])
	{
		dfs(v);
		dp[u][1]+=dp[v][0];
		dp[u][0]+=max(dp[v][0],dp[v][1]);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&y,&x);
		e[x].push_back(y);
		nrt[y]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(!nrt[i])
		{
			dfs(i);
			printf("%d",max(dp[i][0],dp[i][1]));
			break;
		}
	}
	return 0;
}