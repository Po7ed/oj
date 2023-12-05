#include <iostream>
#include <string>
using namespace std;

const int N=1145;
int n,m,fx,fy,bx,by;
int dp[N][N],pos[2][N][2];
string f,b;

const int d[4][2]=
{//  x y
	{0,1},// N
	{1,0},// E
	{0,-1},// S
	{-1,0}// W
};

inline void init()
{
	pos[0][0][0]=fx;
	pos[0][0][1]=fy;
	pos[1][0][0]=bx;
	pos[1][0][1]=by;
	for(int i=0;i<n;i++)
	{
		if(f[i]=='N')
		{
			pos[0][i+1][0]=pos[0][i][0]+d[0][0];
			pos[0][i+1][1]=pos[0][i][1]+d[0][1];
		}
		else if(f[i]=='E')
		{
			pos[0][i+1][0]=pos[0][i][0]+d[1][0];
			pos[0][i+1][1]=pos[0][i][1]+d[1][1];
		}
		else if(f[i]=='S')
		{
			pos[0][i+1][0]=pos[0][i][0]+d[2][0];
			pos[0][i+1][1]=pos[0][i][1]+d[2][1];
		}
		else if(f[i]=='W')
		{
			pos[0][i+1][0]=pos[0][i][0]+d[3][0];
			pos[0][i+1][1]=pos[0][i][1]+d[3][1];
		}
	}
	for(int j=0;j<m;j++)
	{
		if(b[j]=='N')
		{
			pos[1][j+1][0]=pos[1][j][0]+d[0][0];
			pos[1][j+1][1]=pos[1][j][1]+d[0][1];
		}
		else if(b[j]=='E')
		{
			pos[1][j+1][0]=pos[1][j][0]+d[1][0];
			pos[1][j+1][1]=pos[1][j][1]+d[1][1];
		}
		else if(b[j]=='S')
		{
			pos[1][j+1][0]=pos[1][j][0]+d[2][0];
			pos[1][j+1][1]=pos[1][j][1]+d[2][1];
		}
		else if(b[j]=='W')
		{
			pos[1][j+1][0]=pos[1][j][0]+d[3][0];
			pos[1][j+1][1]=pos[1][j][1]+d[3][1];
		}
	}
}

inline int dis(int _x,int _y,int __x,int __y)
{
	return (_x-__x)*(_x-__x)+(_y-__y)*(_y-__y);// '+' -> '*'
}

int main()
{
	scanf("%d %d\n%d %d\n%d %d",&n,&m,&fx,&fy,&bx,&by);
	cin>>f>>b;
	init();
	fill(*dp,*dp+N*N,0x3f3f3f3f);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i||j)
			{
				if(i)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j]);
				}
				if(j)
				{
					dp[i][j]=min(dp[i][j],dp[i][j-1]);
				}
				if(i&&j)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
				}
				dp[i][j]+=dis(pos[0][i][0],pos[0][i][1],pos[1][j][0],pos[1][j][1]);
			}
			else
			{
				dp[i][j]=0;
			}
			// printf("%d %d:%d (%d,%d;%d,%d)\n",i,j,dp[i][j],pos[0][i][0],pos[0][i][1],pos[1][j][0],pos[1][j][1]);
		}
	}
	printf("%d",dp[n][m]);
	return 0;
}