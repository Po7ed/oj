#include <iostream>
using namespace std;
int main()
{
	int n=0,c=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(a[i]>a[j])
				c++;
	printf("%d",c);
	// printf("%.1lf%%",(double)c/(n*(n-1)/2)*100);
	system("pause>nul");
	return 0;
}