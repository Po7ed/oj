#include <iostream>
using namespace std;

typedef long long ll;
ll a[11],b[11];
int n;

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

inline ll inv(ll a,ll p)
{
	ll x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}

ll CRT()
{
	ll p=1,r,x=0;
	for(int i=1;i<=n;i++)
	{
		p*=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		r=p/a[i];
		x+=((b[i]*r*inv(r,a[i]))%p);
		x%=p;
	}
	return x;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",a+i,b+i);
	}
	printf("%lld",CRT());
	return 0;
}