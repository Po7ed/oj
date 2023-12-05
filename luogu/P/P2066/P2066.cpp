#include <iostream>
using namespace std;

int f[11][16],ans[11][16][11];
int a[11][16];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	// fill(*f,*f+(n+1)*(m+1),0);
	// fill(**ans,**ans+(n+1)*(m+1)*(n+1),0);
	// f[0][0]=0;
	/* for(int i=1;i<=n;i++)
	{
		f[i][0]=0;
	} */
	/* for(int j=0;j<=m;j++)
	{
		f[0][j]=0;
	} */
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=j;k++)
			{
				if(f[i][j]<=f[i-1][j-k]+a[i][k])
				{
					f[i][j]=f[i-1][j-k]+a[i][k];
					// ans[i][j]=k;
					for(int l=1;l<i;l++)
					{
						ans[i][j][l]=ans[i-1][j-k][l];
					}
					ans[i][j][i]=k;
				}
			}
		}
	}
	printf("%d\n",f[n][m]);
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",i,ans[n][m][i]);
	}
	return 0;
}