#include <iostream>
#include <string.h>
using namespace std;
const int INF=0x3F3F3F3F;
int d[500],am[501][501];
void create_am(int q)
{
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=q;j++)
		{
			am[i][j]=0;
			for(int k=i;k<j;k++)
				am[i][j]+=d[k];
			for(int k=j;k<i;k++)
				am[i][j]+=d[k];
			// printf("%3d",am[i][j]);
		}
		// puts("");
	}
}
int min_dist(int b,int e)
{
	int mid=(e+b)/2,ans=0;
	for(int i=b;i<=e;i++)
		ans+=am[i][mid];
	return ans;
}
int main()
{
	int m;//village
	int n;//school
	scanf("%d %d",&m,&n);
	int f[m+1][n+1];
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			if(i&&j)f[i][j]=INF;
			else f[i][j]=0;
	// cout<<f[m][n]<<endl;
	for(int i=1;i<m;i++)
		scanf("%d",&d[i]);
	create_am(m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			// cout<<"j:"<<j<<" "<<"i:"<<i<<endl;
			for(int k=j;k<=i;k++)
			{
				// cout<<"k:"<<k<<endl;
				int t;
				if(j-1)
					t=f[k-1][j-1]+min_dist(k,i);
				else
					t=min_dist(1,i);
				if(f[i][j]>t)f[i][j]=t;
				// cout<<"t:"<<t<<" f[i][j]:"<<f[i][j]<<" md(k+1,i):"<<min_dist(k+1,i)<<endl;
			}
		}
	printf("%d",f[m][n]);
	return 0;
}