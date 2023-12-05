#include <iostream>
#include <bitset>
using namespace std;

typedef long long ll;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	if(n%4==1)
	{
		printf("%lld",(n+1)/2-1);
	}
	else
	{
		printf("%lld",(((n-1)/4)*4+2)/2);
	}
	return 0;
}