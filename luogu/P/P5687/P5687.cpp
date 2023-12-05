#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N=314514;
ll a[N],b[N];
ll sa=1,sb=1,n,m;

int main()
{
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",b+i);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	ll ans=a[1]*(m-1ll)+b[1]*(n-1ll);
	for(int cura=2,curb=2;cura<=n&&curb<=m;)
	{
		if(a[cura]<=b[curb])
		{
			ans+=a[cura]*(m-sb);
			cura++;
			sa++;
		}
		else
		{
			ans+=b[curb]*(n-sa);
			curb++;
			sb++;
		}
	}
	printf("%lld",ans);
	return 0;
}