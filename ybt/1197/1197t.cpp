#include <iostream>
#include <string.h>
using namespace std;
const int n=6;
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
			printf("%3d",am[i][j]);
		}
		puts("");
	}
}
int min_dist(int b,int e)
{
	int mid=(e-b)/2,ans=0;
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
			if(i&&j)f[i][j]=0x3F3F3F3F;
			else f[i][j]=0;
	for(int i=1;i<m;i++)
		scanf("%d",&d[i]);
	create_am(m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j-1;k<i;k++)
			{
				int t=f[k][j-1]+min_dist(k+1,i);
					if(f[i][j]>t)f[i][j]=t;
			}
	printf("%d",f[m][n]);
	return 0;
}