#include <stdio.h>
using namespace std;

int main()
{
	unsigned long long n,l,r;
	scanf("%llu %llu %llu",&n,&l,&r);
	unsigned long long k=l+((n-1)-l%n);
	if(k>=r)
		printf("%llu",r%n);
	else
		printf("%llu",n-1);
	return 0;
}