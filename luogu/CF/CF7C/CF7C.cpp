#include <iostream>
using namespace std;

typedef long long ll;

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b){x=1ll,y=0ll;return;}
	exgcd(b,a%b,y,x),y-=a/b*x;return;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main()
{
	ll a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);c=-c;
	if(c%gcd(a,b)!=0){puts("-1");return 0;}
	ll x,y;
	exgcd(a,b,x,y);
	printf("%lld %lld",x*c/gcd(a,b),y*c/gcd(a,b));
	return 0;
}