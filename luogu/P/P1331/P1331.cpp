#include <iostream>
#include <queue>
using namespace std;

int n,m;
char a[1001][1001];

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
	a[x][y]='x';
	point t;
	int mai=-1,maj=-1,mii=10000,mij=10000;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		mai=max(mai,t.x);
		mii=min(mii,t.x);
		maj=max(maj,t.y);
		mij=min(mij,t.y);
		// a[t.x][t.y]='.';
		for(int i=0;i<4;i++)
		{
			if(a[dx][dy]=='#'&&dx>0&&dy>0&&dx<=n&&dy<=m)
			{
				a[dx][dy]='x';
				q.push({dx,dy});
			}
		}
	}
	for(int i=mii;i<=mai;i++)
	{
		for(int j=mij;j<=maj;j++)
		{
			if(a[i][j]!='x')
			{
				puts("Bad placement.");
				exit(0);
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
			a[i][j]=getchar();
			if(a[i][j]!='.'&&a[i][j]!='#')
			{
				a[i][j]=getchar();
			}
			// cin>>a[i][j];
		}
		// getchar();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#')
			{
				bfs(i,j);
			}
		}
	}
	printf("There are %d ships.",cnt);
	return 0;
}
