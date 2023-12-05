#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> p;
#define x first
#define y second

#define kk (k-(int)(!a[i][j]))

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<p> v;
	p t;
	int mx=-1,my=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&t.x,&t.y);
		v.push_back(t);
		mx=max(mx,t.x);
		my=max(my,t.y);
	}
	int a[mx+1+m][my+1+m],dp[mx+1+m][my+1+m][m+1];
	fill(a[0],a[0]+(mx+1+m)*(my+1+m),0);
	for(p tt:v)
	{
		a[tt.x][tt.y]=1;
	}
	fill(dp[0][0],dp[0][0]+(mx+1+m)*(my+1+m)*(m+1),0);
	int mdp=-1;
	for(int i=1;i<=mx+m;i++)
	{
		for(int j=1;j<=my+m;j++)
		{
			dp[i][j][0]=(a[i][j]?max(dp[i-1][j][0],dp[i][j-1][0])+1:0);
			mdp=max(mdp,dp[i][j][0]);
// printf("*%d,%d,%d:%d\n",i,j,0,dp[i][j][0]);
		}
	}
	for(int k=1;k<m;k++)
	{
		for(int i=1;i<=mx+m;i++)
		{
			for(int j=1;j<=my+m;j++)
			{
				// dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0])+1;
				dp[i][j][k]=max(dp[i-1][j][kk],dp[i][j-1][kk])+1;
			mdp=max(mdp,dp[i][j][k]);
// printf("*%d,%d,%d:%d\n",i,j,k,dp[i][j][k]);
			}
		}
	}
	#define k m
	if(!m)
	{
		for(int i=1;i<=mx+m;i++)
		{
			for(int j=1;j<=my+m;j++)
			{
				dp[i][j][k]=max(dp[i-1][j][kk],dp[i][j-1][kk])+1;
	// printf("*%d,%d,%d:%d\n",i,j,k,dp[i][j][k]);
				mdp=max(mdp,dp[i][j][k]);
			}
		}
	}
	printf("%d",mdp);
	return 0;
}