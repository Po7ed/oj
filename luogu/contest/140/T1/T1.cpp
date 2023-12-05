#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	long long n,m,sum;
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&n);
		m=10;
		sum=0;
		while(n)
		{
			m=min(m,n%10);
			sum+=n%10;
			n/=10;
		}
		printf("%d\n",max(sum-m+9,sum+8));
	}
	return 0;
}