#include <iostream>
using namespace std;

typedef long long ll;
ll x,stp,l,r,a,b;

ll get(ll x)
{
	if(x==0)return 1ll;
	if(x>0)
	{
		return x/stp+1;
	}
	else
	{
		return (x+1)/stp;
	}
}

int main()
{
	scanf("%lld %lld %lld %lld",&x,&stp,&l,&r);
	l-=x;r-=x;
	// for(int i=-7;i<=7;i++)printf("get(%d):%lld\n",i,get(i));
	printf("%lld",get(r)-get(l-1));
	return 0;
}