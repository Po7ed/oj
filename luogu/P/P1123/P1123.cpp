#include <iostream>
#include <cstring>
using namespace std;

int n,m;
int a[8][8],vis[8][8];

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

int dfs(int sum=0)
{
	int res=0;
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// if(i>0&&j>0&&i<=n&&j<=m&&!vis[i][j])
			if(!vis[i][j])
			{
				set(i,j);
				res=max(res,dfs(sum+a[i][j]));
				reset(i,j);
				f=false;
			}
		}
	}
	if(f)//last
	{
		return sum;
	}
	return res;
}

int main()
{
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
		printf("%d\n",dfs());
		fill(*a,*a+(n+1)*(m+1),0);
		fill(*vis,*vis+(n+1)*(m+1),0);
	}
	return 0;
}