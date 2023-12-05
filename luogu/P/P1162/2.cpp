#include <iostream>
#include <queue>
using namespace std;

struct point
{
	int x,y;
};

int d[4][2]=
{
	{-1,0},
	{ 1,0},
	{0,-1},
	{0, 1}
};
#define di t.x+d[i][0]
#define dj t.y+d[i][1]

int main()
{
	int n;
	scanf("%d",&n);
	int a[n+2][n+2];
	fill(*a,*a+(n+2)*(n+2),0);
	point b,t;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(!a[i][j])
			{
				b.x=i;
				b.y=j;
			}
		}
	}
	bool in=true;
	queue<point> q;
	q.push(b);
	a[b.x][b.y]=114514;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			/* if(di>0&&dj>0&&di<=n&&dj<=n&&a[di][dj]==0)
			{
				q.push({di,dj});
				a[t.x][t.y]=114514;
			}
			else
			{
				if(di==0||dj==0||di==n+1||dj==n+1)
				{
					q.push({di,dj});
				}
			} */
			if(di>=0&&dj>=0&&di<=n+1&&dj<=n+1&&a[di][dj]==0)
			{
				q.push({di,dj});
				a[di][dj]=114514;
			}
			in=(di>0&&dj>0&&di<=n&&dj<=n)&&in;
		}
	}
	if(in)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%d ",(a[i][j]==114514?2:a[i][j]));
			}
			puts("");
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%d ",(a[i][j]==114514?0:(a[i][j]==0?2:1)));
			}
			puts("");
		}
	}
	return 0;
}
/* 
6
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 0 0 1
1 1 0 0 0 1
1 0 0 0 1 1
1 1 1 1 1 0
 */