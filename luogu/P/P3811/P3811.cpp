#include <iostream>
using namespace std;

typedef long long ll;
ll n,p;

/* template<typename T>
T mod(T a,T b)
{
	return (a%b+b)%b;
} */

ll inv[3114514];
void init()
{
	inv[1]=1ll;
	printf("1\n");
	for(ll i=2;i<=n;i++)
	{
		inv[i]=(p-(p/i))%p*inv[p%i]%p;
		printf("%lld\n",inv[i]);
	}
}

int main()
{
	// freopen("out.txt","w",stdout);
	scanf("%lld %lld",&n,&p);
	init();
	return 0;
}