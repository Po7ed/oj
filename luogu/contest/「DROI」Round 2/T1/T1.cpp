#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long n,k;
		scanf("%lld %lld",&n,&k);
		if(k%(n-k)!=k)
		{
			puts("-1");
		}
		else
		{
			printf("%lld %lld\n",k,n-k);
		}
	}
	return 0;
}