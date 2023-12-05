#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],c=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		int m=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
				m=j;
		}
		if(m!=i)c++;
	}
	printf("%d",c);
	return 0;
}