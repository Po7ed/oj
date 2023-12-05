#include <iostream>
using namespace std;
int main()
{
	int n,a[101],c=0;
	bool f[20000];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			f[a[i]+a[j]]=1;
	for(int i=1;i<=n;i++)
		if(f[a[i]])
			c++;
	printf("%d",c);
	return 0;
}