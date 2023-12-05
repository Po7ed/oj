#include <iostream>
using namespace std;

int main()
{
	int n=0;
	scanf("%d",&n);
	int a=2,b=1;
	n--;
	for(int i=0;i<n;i++)
	{
		int t=a;
		a+=2*b;
		b+=t;
	}
	printf("%d",a+b);
	return 0;
}