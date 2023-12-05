#include <iostream>
using namespace std;

int n;

int a[101][101];
int t(int i,int j,int m)
{
	while(j>0&&i<=n)
	{
		a[i][j]=m++;
		i++;
		j--;
	}
	return m;
}

int main()
{
	scanf("%d",&n);
	int m=1;
	for(int j=1;j<=n;j++)
	{
		m=t(1,j,m);
	}
	for(int i=2;i<=n;i++)
	{
		m=t(i,n,m);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		puts("");
	}
}