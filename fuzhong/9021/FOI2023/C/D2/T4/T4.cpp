#include <iostream>
#include <queue>
using namespace std;

struct point
{
	int x,y;
	int stp;
};

int d[8][2]=
{
	{-2,-1},
	{-2, 1},
	{-1,-2},
	{-1, 2},
	{ 1,-2},
	{ 1, 2},
	{ 2,-1},
	{ 2, 1}
};
#define dx (t.x+d[i][0])
#define dy (t.y+d[i][1])

int main()
{
	int T;
	scanf("%d",&T);
	int n,sx,sy,tx,ty;
	point t;
	while(T--)
	{
		scanf("%d\n%d %d\n%d %d",&n,&sx,&sy,&tx,&ty);
		queue<point> q;
		bool vis[n+1][n+1];
		fill(*vis,*vis+(n+1)*(n+1),false);
		vis[sx][sy]=true;
		q.push({sx,sy,0});
		while(!q.empty())
		{
			t=q.front();
			q.pop();
			if(t.x==tx&&t.y==ty)
			{
				printf("%d\n",t.stp);
				break;
			}
			for(int i=0;i<8;i++)
			{
				if(dx>=0&&dy>=0&&dx<n&&dy<n&&!vis[dx][dy])
				{
					vis[dx][dy]=true;
					q.push({dx,dy,t.stp+1});
				}
			}
		}
	}
	return 0;
}