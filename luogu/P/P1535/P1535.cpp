#include <iostream>
using namespace std;
int cnt;

int x1,y_,x2,y2;
int n,m,t;
char g[101][100];

int d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
};
#define dx (x+d[i][0])
#define dy (y+d[i][1])

inline int abs(int s)
{
    if(s<0)
		return -s;
    return s;
}
// int r[101][101][16];
void dfs(int x,int y,int dep)
{
	if(dep>t||abs(x-x2)+abs(y-y2)>t-dep)
	{
		// r[x][y][dep]=0;
		return;
	}
	if(x==x2&&y==y2&&dep==t)
	{
		cnt++;
		// return;
	}
	/* if(r[x][y][dep]!=-1)
	{
		cnt+=r[x][y][dep];
		return;
	} */
	// int ct=cnt;
	for(int i=0;i<4;i++)
	{
		if(dx>0&&dy>0&&dx<=n&&dy<=m&&g[dx][dy]=='.')
		{
			dfs(dx,dy,dep+1);
		}
	}
	// r[x][y][dep]=cnt-ct;
	return;
}

int main()
{
	// fill(**r,**r+(101)*(101)*(16),-1);
	scanf("%d %d %d\n",&n,&m,&t);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// g[i][j]=getchar();
			cin>>g[i][j];
		}
		// getchar();
	}
	scanf("%d %d %d %d",&x1,&y_,&x2,&y2);
	dfs(x1,y_,0);
	printf("%d",cnt);
	return 0;
}
