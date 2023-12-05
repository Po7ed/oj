#include <iostream>
#include <cstring>
using namespace std;

int n,m;
int a[8][8],vis[8][8],sum,ans;

int d[9][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
	{-1,-1},
	{-1,1},
	{1,-1},
	{1,1},
	{0,0}
};
#define dx (x+d[i][0])
#define dy (y+d[i][1])

inline void set(int x,int y)
{
	for(int i=0;i<9;i++)
	{
		vis[dx][dy]++;
	}
	return;
}
inline void reset(int x,int y)
{
	for(int i=0;i<9;i++)
	{
		vis[dx][dy]--;
	}
	return;
}

void dfs(int x,int y)
{ 
	if(y>m)
	{
		dfs(x+1,1);
		return;
	}
	if(x>n)
	{
		ans=max(sum,ans);
		return;
	}
	dfs(x,y+1);
	if(!vis[x][y])
	{
		sum+=a[x][y];
		set(x,y);
		dfs(x,y+1);
		reset(x,y);
		sum-=a[x][y];
	}
}

int main()
{
	// freopen("apple.in","r",stdin);
	// freopen("apple.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		ans=-0x3f3f3f3f;
		sum=0;
		dfs(1,1);
		printf("%d\n",ans);
		fill(*a,*a+(n+1)*(m+1),0);
		fill(*vis,*vis+(n+1)*(m+1),0);
	}
	return 0;
}