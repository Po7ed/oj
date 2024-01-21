#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll a,b,n;
	scanf("%lld %lld %lld",&a,&b,&n);
	printf("%lld",min(a-a%b,n*b));
	return 0;
}