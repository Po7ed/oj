#include <iostream>
#include <vector>
using namespace std;

int n,m;
int a[1001][1001];
int b[1001][1001];

int d[4][2]=
{
	{-1,0},
	{ 1,0},
	{0,-1},
	{0, 1}
};

#define dx (p.x+d[i][0])
#define dy (p.y+d[i][1])
#define tox (dx+d[a[dx][dy]][0])
#define toy (dy+d[a[dx][dy]][1])

struct point
{
	int x,y;
};

vector<point> o;

void dfs(point p)
{
	if(b[p.x][p.y])
		return;
	b[p.x][p.y]=1;
	for(int i=0;i<4;i++)
	{
		if(tox==p.x&&toy==p.y&&dx>0&&dy>0&&dx<=n&&dy<=m)
		{
			dfs({dx,dy});
		}
	}
	return;
}

int main()
{
	scanf("%d %d\n",&m,&n);
	char c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c=getchar();
			switch(c)
			{
				case 'o':a[i][j]=-1;break;
				case 'u':a[i][j]=0;break;
				case 'd':a[i][j]=1;break;
				case 'l':a[i][j]=2;break;
				case 'r':a[i][j]=3;break;
				// default:a[i][j]=F;break;
			}
			if(a[i][j]==-1)
			{
				o.push_back({i,j});
			}
		}
		getchar();
		getchar();
	}
	for(point p:o)
	{
		dfs({p.x,p.y});
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt+=b[i][j];
		}
	}
	printf("%d",cnt);
	return 0;
}