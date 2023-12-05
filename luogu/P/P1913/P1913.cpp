#include <iostream>
using namespace std;

#define T 114514
#define F 1919810
int n,m;
int b[1001][1001];
int a[1001][1001];

int d[4][2]=
{
	{-1,0},
	{ 1,0},
	{0,-1},
	{0, 1}
};

#define dx (x+d[a[x][y]][0])
#define dy (y+d[a[x][y]][1])

int Find(int x,int y)
{
	if(a[x][y]==T)
	{
		b[x][y]=T;
		return T;
	}
	if(b[x][y])
		return b[x][y];
	if(dx>0&&dy>0&&dx<=n&&dy<=m)
		return b[x][y]=Find(dx,dy);
	else
	{
		b[x][y]=F;
		return F;
	}
	return F;
}

int main()
{
	freopen("G:\\zjd\\C++Code\\oj\\luogu\\P1913\\1000 1000.txt","r",stdin);
	scanf("%d %d\n",&n,&m);
	char c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c=getchar();
			switch(c)
			{
				case 'o':a[i][j]=T;break;
				case 'u':a[i][j]=0;break;
				case 'd':a[i][j]=1;break;
				case 'l':a[i][j]=2;break;
				case 'r':a[i][j]=3;break;
				default:a[i][j]=F;break;
			}
		}
		getchar();
		getchar();
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(Find(i,j)==T)
			{
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}