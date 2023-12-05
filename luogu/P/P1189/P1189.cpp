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
	{1,0},
	{0,-1},
	{0,1}
};

#define dx (i+d[opt][0]*l)
#define dy (j+d[opt][1]*l)

int main()
{
	freopen("P1189_2.in","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	scanf("%d %d\n",&n,&m);
	int a[n+1][m+1];
	char c;
	bool vis[n+1][m+1],now[n+1][m+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// scanf("%c",&a[i][j]);
			// cin>>a[i][j];
			vis[i][j]=now[i][j]=false;
			c=getchar();
			if(c=='.')
			{
				a[i][j]=1;
			}
			else if(c=='X')
			{
				a[i][j]=0;
			}
			else if(c=='*')
			{
				// q.push({i,j});
				vis[i][j]=true;
				a[i][j]=1;
			}
		}
		scanf("\n");
	}
	int k;
	scanf("%d",&k);
	string s;
	int opt;
	for(int o=1;o<=k;o++)
	{
		cin>>s;
		if(s[0]=='N')
		{
			opt=0;
		}
		else if(s[0]=='S')
		{
			opt=1;
		}
		else if(s[0]=='W')
		{
			opt=2;
		}
		else if(s[0]=='E')
		{
			opt=3;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j])
				{
					for(int l=1;(dx>0&&dy>0&&dx<=n&&dy<=m&&a[dx][dy]);l++)
					{
						now[dx][dy]=true;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				vis[i][j]=now[i][j];
				now[i][j]=false;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j])
			{
				a[i][j]=2;
			}
			printf("%c","X.*"[a[i][j]]);
		}
		puts("");
	}
	return 0;
}