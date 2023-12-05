#include <iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int s[n+2][n+2];
	fill(*s,*s+(n+2)*(n+2),0);
	int x1,y1,x2,y2;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		s[x1][y1]++;
		s[x2+1][y2+1]++;
		s[x1][y2+1]--;
		s[x2+1][y1]--;
	}
	/* for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%d ",s[i][j]);
		}
		puts("");
	} */
	int a[n+2][n+2];
	fill(*a,*a+(n+2)*(n+2),0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+s[i][j];
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}