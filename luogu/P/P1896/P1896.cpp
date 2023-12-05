#include <iostream>
#include <bitset>
using namespace std;

typedef long long ll;
const int N=10;
bitset<N> vis[N];
int n,k;

const int d[9][2]=
{
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,0},
	{0,1},
	{1,-1},
	{1,0},
	{1,1}
};

inline bool check(int x,int y)
{
	bool res=false;
	for(int i=0;i<9;i++)
	{
		res=res||vis[x+d[i][0]][y+d[i][1]];
	}
	return !res;
}

ll dfs(int x,int y,int z=k-1)
{
	vis[x][y]=true;
	ll res=0;
	if(z==0)
	{
		/* for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[i][j])
				{
					printf("*%d %d\n",i,j);
				}
			}
		}
		puts(""); */
		vis[x][y]=false;
		return 1ll;
	}
	for(int j=y+2;j<=n;j++)
	{
		if(check(x,j))
		{
			res+=dfs(x,j,z-1);
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(check(i,j))
			{
				res+=dfs(i,j,z-1);
			}
		}
	}
	vis[x][y]=false;
	return res;
}

int main()
{
	scanf("%d %d",&n,&k);
	ll ans=0;
	if((n+(n&1))*(n+(n&1))/4<k)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans+=dfs(i,j);
		}
	}
	printf("%lld",ans);
	return 0;
}