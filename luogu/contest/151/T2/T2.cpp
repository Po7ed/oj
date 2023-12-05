#include <iostream>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	if(n&1)
	printf("%lld",(n+1)*n/4);
	else
	printf("%lld",n*n/4);
	return 0;
}