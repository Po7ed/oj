#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct palce
{
	int x,y,dir;
}p;

#define up 0
#define down 1
#define left 2
#define right 3
int d[4][2]=
{
	{ 1,0},
	{-1,0},
	{0, 1},
	{0,-1}
};
#define dx (t.x+d[t.dir][0])
#define dy (t.y+d[t.dir][1])
#define ddx (tx+d[dir^1][0])
#define ddy (ty+d[dir^1][1])
int dd[4][2]=
{
	{0,-1},
	{0, 1},
	{ 1,0},
	{-1,0}
};
#define rx (t.x+dd[t.dir][0])
#define ry (t.y+dd[t.dir][1])
#define lx (t.x+dd[t.dir^1][0])
#define ly (t.y+dd[t.dir^1][1])
// auto turn=[](int dir)->int{return (dir<2?dir+2:(dir==2?1:0));};
auto turn=[](int dir)->int{return (dir<2?dir+2:(dir==2?1:0));};

int main()
{
	int n,m,q;
	scanf("%d %d %d\n",&n,&m,&q);
	char a[n+1][m+1];
	queue<p> edge;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar();
			if(a[i][j]=='o')
			{
				if(i==1)
				{
					edge.push({i,j,up});
				}
				if(j==1)
				{
					edge.push({i,j,left});
				}
				if(i==n)
				{
					edge.push({i,j,down});
				}
				if(j==m)
				{
					edge.push({i,j,right});
				}
			}
		}
		getchar();
		// getchar();
	}
	p t;
	bool vis[n+1][m+1][4];
	fill(**vis,**vis+(n+1)*(m+1)*(4),false);
	while(!edge.empty())
	{
		t=edge.front();
		edge.pop();
		if(t.x>0&&t.y>0&&t.x<=n&&t.y<=m&&!vis[t.x][t.y][t.dir])
		{
			vis[t.x][t.y][t.dir]=true;
			if(a[dx][dy]=='o')
			{
				edge.push({dx,dy,t.dir});
			}
			if(a[rx][ry]=='x')// &&(a[lx][ly]=='o'||lx<1||ly<1||lx>n||ly>m)
			{
				edge.push({t.x,t.y,turn(t.dir)});
			}
			/* else
			{
				edge.push({rx,ry,turn(t.dir)});
			} */
		}
	}
	int x,y,tx,ty;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&x,&y);
		for(int dir=0;dir<4;dir++)
		{
			tx=x;
			ty=y;
			while(a[tx][ty]=='o'&&tx>0&&ty>0&&tx<=n&&ty<=m)
			{
				if(vis[tx][ty][dir])
				{
					break;
				}
				tx=ddx;
				ty=ddy;
			}
			if(a[tx][ty]=='o'&&tx>0&&ty>0&&tx<=n&&ty<=m)
			{
				printf("Y");
			}
			else if(!(tx>0&&ty>0&&tx<=n&&ty<=m))
			{
				printf("Y");
			}
			else
			{
				printf("N");
			}
		}
		puts("");
	}
	return 0;
}