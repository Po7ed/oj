#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	int T,n,x;
	scanf("%d",&T);
	while(T--)
	{
		ll d=0,xx;
		scanf("%d %d",&n,&x);
		if(n==2)
		{
			printf("%d\n",x);
			continue;
		}
		xx=x;
		while(xx&&(xx&1)!=1)
		{
			xx>>=2;
			d++;
		}
		if(!xx)
		{
			d++;
		}
		if(x==2)d=1;
		xx=x>>d;
		// printf("xx%lld\n",xx);
		printf("%lld\n",xx<<(n-2));
		// k=n-d-2;
		// printf("%lld\n",(ll)x<<k);
	}
	return 0;
}