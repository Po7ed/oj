#include <iostream>
using namespace std;

/* 
#define up 0
#define left 1
#define down 2
#define right 3
 */
const int d[4][2]=
{
	{-1,0},
	{0,-1},
	{1,0},
	{0,1}
};
#define di i+d[k][0]
#define dj j+d[k][1]

int main()
{
	int n;
	scanf("%d",&n);
	char a[n+1][n+1];
	int x,y;
	int dp[n+1][n+1][4];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=dp[i][j][3]=114514;
			if(a[i][j]=='B')
			{
				x=i;
				y=j;
			}
			else if(a[i][j]=='A')
			{
				dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=dp[i][j][3]=0;
			}
		}
	}
	for(int l=0;l<n*10;l++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=0;k<4;k++)
				{
					if(a[i][j]!='x'&&di>0&&dj>0&&di<=n&&dj<=n)
					{
						dp[i][j][k]=min(min(dp[di][dj][k],dp[di][dj][(k+1)%4]+1),min(dp[di][dj][(k+3)%4]+1,dp[i][j][k]));
					}
// printf("*(%d,%d,%d)=%d\n",i,j,k,dp[i][j][k]);
				}
			}
		}
	}
	int ans=min(min(dp[x][y][0],dp[x][y][1]),min(dp[x][y][2],dp[x][y][3]));
	printf("%d",(ans==114514?-1:ans));
	return 0;
}