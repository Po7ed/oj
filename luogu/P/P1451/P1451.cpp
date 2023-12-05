#include <iostream>
#include <queue>
using namespace std;

int n,m;
int a[101][101];

struct point
{
	int x,y;
};

const int d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
#define dx (t.x+d[i][0])
#define dy (t.y+d[i][1])

int cnt;

void bfs(int x,int y)
{
	cnt++;
	// a[x][y]=0;
	queue<point> q;
	q.push({x,y});
	point t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		a[t.x][t.y]=0;
		for(int i=0;i<4;i++)
		{
			if(a[dx][dy]&&dx>0&&dy>0&&dx<=n&&dy<=m)
			{
				a[dx][dy]=0;
				q.push({dx,dy});
			}
		}
	}
}

int main()
{
	scanf("%d %d\n",&n,&m);
	// fill(*a,*a+(n+1)*(m+1),0);
	for(int i=1;i<=n;i++)
	{
		// a[0][i]=0;
		// a[i][0]=0;
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar()-'0';
		}
		getchar();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				bfs(i,j);
			}
		}
	}
	printf("%d",cnt);
	return 0;
}