#include <iostream>
#include <bitset>
using namespace std;

constexpr int N=20,M=(1<<N)+114;
bitset<M<<1> can;
bitset<N+3> dis[N+3];
int n,m;

int now[N+1],cnt,vis;
void dfs(int pos,int rem)
{
	if(!rem)
	{
		if(!can[vis^(1<<now[0])])return;
		for(int i=1;i<cnt;i++)
		{
			if(dis[now[0]][now[i]])return;
		}
		can[vis]=true;
		return;
	}
	for(int i=pos+1;i<=n;i++)
	{
		vis|=(1<<i);now[cnt++]=i;
		dfs(i,rem-1);
		vis^=(1<<i);cnt--;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		dis[x][y]=true;
		dis[y][x]=true;
	}
	can[0]=1;
	for(int i=1;i<=n;i++)dfs(0,i);
	int ans=0;
	for(int i=0;i<(1<<n);i++)ans+=can[i<<1];
	printf("%d",ans);
	return 0;
}