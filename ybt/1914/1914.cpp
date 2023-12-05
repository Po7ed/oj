#include <iostream>
using namespace std;
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[1001];
	for(int i=1;i<=n;i++) a[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i/2;j++)
			a[i]+=a[j];
	printf("%d",a[n]);
	return 0;
}