#include <iostream>
using namespace std;
unsigned long long fib(int n)
{
	unsigned long long temp;
	if(n<1)
		return -1;
	unsigned long long *a=new unsigned long long [n+1];
	a[1]=0;a[2]=1;
	for(int i=3;i<=n;i++)
	{
		a[i]=a[i-2]+a[i-1];
	}
	temp=a[n];
	delete []a;
	return temp;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%llu",fib(n));
}