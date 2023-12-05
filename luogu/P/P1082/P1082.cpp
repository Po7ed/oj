#include <iostream>
using namespace std;

typedef long long ll;

void exgcd(ll a,ll b,ll& x,ll& y)
{
	if(!b)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}

int main()
{
	ll n,p;
	scanf("%lld %lld",&n,&p);
	ll x,y;
	exgcd(n,p,x,y);
	printf("%lld",(x%p+p)%p);
	return 0;
}