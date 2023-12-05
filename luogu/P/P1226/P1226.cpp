#include <iostream>
using namespace std;

int main()
{
	long long a,b,p;
	scanf("%lld %lld %lld",&a,&b,&p);
	long long aa=a,bb=b;
	long long r=1;
	while(b>0)
	{
		if(b&1)
			r=r*a%p;
		a=a*a%p;
		b>>=1;
	}
	printf("%lld^%lld mod %lld=%lld",aa,bb,p,r);
}