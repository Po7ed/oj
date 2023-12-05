#include <iostream>
#include <bitset>
using namespace std;

constexpr int N=514;
int n,m,q;
bitset<4> mem[N][N],set[N][N];
bitset<N> a[N];
char s[N];

constexpr int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}},t[4]={3,2,0,1};
#define dx (x+d[dir][0])
#define dy (y+d[dir][1])
// #define tx (x+d[t[dir]][0])
// #define ty (y+d[t[dir]][1])
bitset<4> vis[N][N];
bool dfs(int x,int y,int dir)// true: can't
{
	if(set[x][y][dir])return mem[x][y][dir];
	if(vis[x][y][dir])return mem[x][y][dir]=true;
	vis[x][y][dir]=true;
	if(dx<=0||dy<=0||dx>n||dy>m)
	{
		set[x][y][dir]=true,mem[x][y][dir]=false;
		return false;
	}
	if(!a[dx][dy])
	{
		mem[x][y][dir]=dfs(x,y,t[dir]);
	}
	else
	{
		mem[x][y][dir]=dfs(dx,dy,dir);
	}
	set[x][y][dir]=true;
	vis[x][y][dir]=false;
	return mem[x][y][dir];
}

int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='o')a[i][j]=true;
		}
	}
	int x,y;
	while(q--)
	{
		scanf("%d %d",&x,&y);
		for(int i=0;i<4;i++)
		{
			printf(dfs(x,y,i)?"N":"Y");
		}
		puts("");
	}
	return 0;
}