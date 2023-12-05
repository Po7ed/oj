#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	long long n,m;
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		if(n==m)
		{
			puts("0");
		}
		else if(((n&m)==n)||((n&m)==m))
		{
			puts("1");
		}
		else
		{
			puts("2");
		}
	}
	return 0;
}