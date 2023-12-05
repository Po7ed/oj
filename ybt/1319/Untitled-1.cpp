#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1][2];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		a[i][1]=i;
	}
	for(int i=n;i>=1;i--)
		for(int j=1;j<i;j++)
			if(a[j][0]>a[j+1][0])
				swap(a[j],a[j+1]);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i][1]);
	puts("");
	double ave=0;
	for(int i=1;i<=n;i++)
		ave+=(a[i][0]*(n-i));
	ave/=n;
	printf("%.2lf",ave);
	return 0;
}