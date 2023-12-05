#include <iostream>
using namespace std;

double fac[16];

int main()
{
	int n;
	scanf("%d",&n);
	double e;
	fac[0]=1;
	for(int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i;
	}
	for(int i=1;i<=n;i++)
	{
		e+=((double)1/fac[i]);
	}
	printf("%.10lf",e+1);
	return 0;
}