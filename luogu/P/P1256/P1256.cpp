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
#define dist (dis[t.x][t.y]+1)

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1];
	int dis[n+1][m+1];
	fill(*dis,*dis+(n+1)*(m+1),0x3f3f3f3f);
	// vector<point> w;
	queue<point> q;
	char c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// scanf("%d",&a[i][j]);
			cin>>c;
			a[i][j]=c-'0';
			if(a[i][j])
			{
				q.push({i,j});
				dis[i][j]=0;
			}
		}
	}
	point t;	
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(dx>0&&dy>0&&dx<=n&&dy<=m&&!a[dx][dy]&&dis[dx][dy]==0x3f3f3f3f)
			{
				q.push({dx,dy});
				dis[dx][dy]=dist;
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