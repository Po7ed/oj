#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
constexpr int N=214514;
int n,q;
ll a[N];

int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	ll x;
	for(int i=0;i<q;i++)
	{
		scanf("%lld",&x);
		printf("%lld\n",upper_bound(a+1,a+n+1,x)-a-1);
	}
	return 0;
}