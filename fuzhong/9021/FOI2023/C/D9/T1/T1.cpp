#include <iostream>
using namespace std;
int main()
{
	long long a,b,k,d,p;
	scanf("%lld %lld\n%lld %lld %lld",&a,&b,&k,&d,&p);
	long long mi=d+p+b/* max(d+p+b,k-a) */,ma=d+p+k;
	if(ma<mi)
	{
		puts("-1");
	}
	else
	{
		printf("%lld",mi);
	}
	return 0;
}