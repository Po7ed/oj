#include <iostream>
using namespace std;
int a[1001][1001];
int main()
{
	int r,m;
	scanf("%d",&r);
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
		}
	}
	for(int i=1;i<=r;i++)
		m=max(m,a[r][i]);
	printf("%d",m);
	return 0;
}