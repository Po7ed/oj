#include <iostream>
using namespace std;

int main()
{
	int a[10];
	for(int i=0;i<10;i++)
		scanf("%d",&a[i]);
	int n=0,c=0;
	scanf("%d",&n);
	for(int i=0;i<10;i++)
	{
		if(a[i]<=n+30)
			c++;
	}
	printf("%d",c);
	return 0;
}