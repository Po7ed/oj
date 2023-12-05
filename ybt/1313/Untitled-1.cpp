#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if(n==1){printf("9\n");return 0;}
	unsigned long long e=8,o=1;
	for(int i=2;i<=n;i++)
	{
		unsigned long long te=e,to=o;
		e=(te*9+to)%12345;
		o=(to*9+te)%12345;
	}
	printf("%llu\n",e);
	return 0;
}