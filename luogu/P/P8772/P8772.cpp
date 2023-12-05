#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	scanf("%d",&n);
	ll a[n+1],sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans+=(a[i]*(sum-a[i]));
	}
	printf("%lld",ans/2);
	return 0;
}