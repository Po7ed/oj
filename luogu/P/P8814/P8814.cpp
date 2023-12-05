#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define delta ((n-e*d+2)*(n-e*d+2)-4*n)
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll n,e,d;
		scanf("%lld %lld %lld",&n,&d,&e);
		if(delta<0||(double)sqrt(delta)!=(double)floor((double)sqrt((double)delta)))
		{
			puts("NO");
		}
		else
		{
			ll x1=(ll)(n-e*d+2-(ll)sqrt((double)delta))/2;
			ll x2=(ll)(n-e*d+2+(ll)sqrt((double)delta))/2;
			/* if(x1*x2==n)
			{ */
				printf("%lld %lld\n",x1,x2);
			/* }
			else
			{
				puts("NO");
			} */
		}
	}
	return 0;
}