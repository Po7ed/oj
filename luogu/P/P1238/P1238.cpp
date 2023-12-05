#include <iostream>
#include <vector>
using namespace std;

int m,n;
int bi,bj,ei,ej;
int a[15][15];
int baga=true;

struct point
{
	int x,y;
};

const int d[4][2]=
{
	{0,-1},
	{-1,0},
	{0,1},
	{1,0}
};
#define dx (x+d[i][0])
#define dy (y+d[i][1])

vector<point> v;
bool vis[15][15];
void dfs(int x,int y)
{
	if(x==ei&&y==ej)
	{
		baga=false;
		bool f=true;
		for(point t:v)
		{
			printf((f?"(%d,%d)":"->(%d,%d)"),t.x,t.y);
			f=false;
		}
		puts("");
		return;
	}
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		if(!vis[dx][dy]&&a[dx][dy]&&dx>0&&dy>0&&dx<=m&&dy<=n)
		{
			vis[dx][dy]=true;
			v.push_back({dx,dy});
			dfs(dx,dy);
			v.pop_back();
			vis[dx][dy]=false;
		}
	}
	return;
}

int main()
{
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d\n%d %d",&bi,&bj,&ei,&ej);
	v.push_back({bi,bj});
	dfs(bi,bj);
	if(baga)
	{
		puts("-1");
	}
	return 0;
}