#include <iostream>
using namespace std;

char a[5][6];
int d[4][2]
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
#define dx (x+d[i][0])
#define dy (y+d[i][1])
#define dx_ (x+d[f[from]][0])
#define dy_ (y+d[f[from]][1])

int f[4]={1,0,3,2};

bool vis[5][5];

int H=0;

long long dfs(int x,int y,int dep,/* int H, */int from)
{
	if(a[x][y]=='H')
	{
		H++;
	}
	if(H>3)
	{
		if(a[x][y]=='H')
		{
			H--;
		}
		return 0;
	}
	if(dep==7)
	{
		if(a[x][y]=='H')
		{
			H--;
		}
		return 1;
	}
	long long r=0;
	for(int i=0;i<4;i++)//1
	{
		if(dx>=0&&dy>=0&&dx<5&&dy<5&&i!=from)
		{
			vis[dx][dy]=true;
			r+=dfs(dx,dy,dep+1,f[i]);
			vis[dx][dy]=false;
		}
	}
	if(dep+2>7)
	{
		if(a[x][y]=='H')
		{
			H--;
		}
		return r;
	}
	for(int i=0;i<4;i++)//2
	{
		if(dx>=0&&dy>=0&&dx<5&&dy<5&&dx_>=0&&dy_>=0&&dx_<5&&dy_<5&&i!=from&&i!=f[from])
		{
			vis[dx][dy]=vis[dx_][dy_]=true;
			r+=dfs(dx,dy,dep+1,f[i]);
			r+=dfs(dx_,dy_,dep+2,from);
			vis[dx][dy]=vis[dx_][dy_]=false;
		}
	}
	if(dep+3>7)
	{
		if(a[x][y]=='H')
		{
			H--;
		}
		return r;
	}
	for(int i=0;i<4;i++)//3
	{
		if(dx>=0&&dy>=0&&dx<5&&dy<5)
		{
			vis[dx][dy]=true;
		}
	}
	// vis[dx][dy]=vis[dx_][dy_]=vis[][]=true;
	int td=dep+1;
	for(int i=0;i<4;i++)
	{
		if(i!=from&&dx>=0&&dy>=0&&dx<5&&dy<5)
		{
			r+=dfs(dx,dy,td++,f[i]);
		}
	}
	for(int i=0;i<4;i++)
	{
		if(dx>=0&&dy>=0&&dx<5&&dy<5)
		{
			vis[dx][dy]=false;
		}
	}
	if(from!=-1)
		vis[(x+d[from][0])][(y+d[from][1])]=true;
	if(a[x][y]=='H')
	{
		H--;
	}
	return r;
}

int main()
{
	long long ans=0;
	scanf("%s\n%s\n%s\n%s\n%s",&a[0],&a[1],&a[2],&a[3],&a[4]);
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			vis[i][j]=true;
			ans+=dfs(i,j,1,-1);
			vis[i][j]=false;
		}
	}
	// ans/=7;
	printf("%lld",ans);
	return 0;
}