#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1][n+1];
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			a[i][j]=(j+i-2)%(n-1)+1;
		}
	}
	/* for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		puts("");
	} */
	for(int i=1;i<n;i++)
	{
		a[i][n]=a[i][i];
		// a[i][i]=0;
	}
	for(int j=1;j<n;j++)
	{
		a[n][j]=a[j][j];
		a[j][j]=0;
	}
	a[n][n]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}