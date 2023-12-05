#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point
{
	int x,y;
};

int d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

#define dx (t.x+d[i][0])
#define dy (t.y+d[i][1])
#define dist (abs(dx-p.x)+abs(dy-p.y))

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1];
	int dis[n+1][m+1];
	fill(*dis,*dis+(n+1)*(m+1),0x3f3f3f3f);
	vector<point> w;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j])
			{
				w.push_back({i,j});
				dis[i][j]=0;
			}
		}
	}
	queue<point> q;
	point t;
	for(point p:w)
	{
		bool vis[n+1][m+1];
		fill(*vis,*vis+(n+1)*(m+1),false);
		q.push(p);
		vis[p.x][p.y]=true;
		while(!q.empty())
		{
			t=q.front();
			q.pop();
			for(int i=0;i<4;i++)
			{
				if(dx>0&&dy>0&&dx<=n&&dy<=m&&!vis[dx][dy]&&!a[dx][dy])
				{
					q.push({dx,dy});
					dis[dx][dy]=min(dis[dx][dy],dist);
					vis[dx][dy]=true;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",dis[i][j]);
		}
		puts("");
	}
	return 0;
}