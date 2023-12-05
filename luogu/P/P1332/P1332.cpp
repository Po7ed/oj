#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point
{
	int x,y;
	// int dep;
};

int d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

#define dx (t.x+d[j][0])
#define dy (t.y+d[j][1])

int main()
{
	freopen("P1332_2.in","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,u,v;//u yuan;v zhu
	scanf("%d %d %d %d",&n,&m,&u,&v);
	int a[n+1][m+1],x,y;
	fill(*a,*a+(n+1)*(m+1),0x3f3f3f3f);
	/* for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			
		}
	} */
	// int mas[v+1][2];
	point t;
	bool vis[n+1][m+1];
	queue<point> q;
	for(int i=1;i<=u;i++)
	{
		scanf("%d %d",&x,&y);
		a[x][y]=0;
		vis[x][y]=true;
		q.push({x,y});
	}
	fill(*vis,*vis+(n+1)*(m+1),false);
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(int j=0;j<4;j++)
		{
			if(dx>0&&dy>0&&dx<=n&&dy<=m&&!vis[dx][dy])
			{
				vis[dx][dy]=true;
				a[dx][dy]=min(a[dx][dy],a[t.x][t.y]+1);
				q.push({dx,dy});
			}
		}
	}
	bre:;
	for(int i=1;i<=v;i++)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",a[x][y]);
	}
	return 0;
}