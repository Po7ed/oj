#include <iostream>
#include <bit>
using namespace std;

#define lowbit(x) ((x)&(-x))

int main()
{
	int t;
	scanf("%d",&t);
	long long a;
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&a);
		if(__popcount(a)>=3)
		{
			puts("No,Commander");
		}
		else
		{
			if(__popcount(a)==1)
			{
				printf("%lld\n",a+1);
			}
			else
			{
				printf("%lld\n",a-lowbit(a)+2*lowbit(a));
			}
		}
	}
	return 0;
}
