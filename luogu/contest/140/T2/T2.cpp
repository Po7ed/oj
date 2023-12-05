#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	long long n,m;
	for(int i=0;i<t;i++)
	{
		scanf("%ld %lld",&n,&m);
		printf("%lld\n",(2*n*m-n-m));
	}
	return 0;
}