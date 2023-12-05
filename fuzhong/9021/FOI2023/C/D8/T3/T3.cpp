#include <iostream>
using namespace std;
int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	int a[n+2][m+2],b[n+2][m+2];
	fill(*b,*b+(n+2)*(m+2),0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j]+=a[i][j];
			b[i][j+1]-=a[i][j];
			b[i+1][j]-=a[i][j];
			b[i+1][j+1]+=a[i][j];
		}
	}
	fill(*a,*a+(n+2)*(m+2),0);
	int x1,y1,x2,y2,c;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
		b[x1][y1]+=c;
		b[x1][y2+1]-=c;
		b[x2+1][y1]-=c;
		b[x2+1][y2+1]+=c;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}