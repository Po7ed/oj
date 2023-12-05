#include <iostream>
using namespace std;

typedef long long ll;

ll mod(ll b,ll p,ll k)
{
	if(p==1)return b%k;
	int m=p/2;
	return mod(b,m,k)*mod(b,p-m,k)%k;
}

int main()
{
	ll b,p,k;
	scanf("%lld %lld %lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,mod(b,p,k));
	return 0;
}