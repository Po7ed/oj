#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	// freopen("genshin5.in","r",stdin);
	// freopen("out.txt","w",stdout);
	ll n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	ll a[n+1],b[m+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+(n+1));
	reverse(a+1,a+(n+1));
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",b+i);
	}
	sort(b+1,b+(m+1));
	reverse(b+1,b+(m+1));
	ll l,l_,*c;
	if(n>m)
	{
		l=m;
		l_=n;
		c=a;
	}
	else
	{
		l=n;
		l_=m;
		c=b;
	}
	ll ans=0;
	for(int i=1;i<=l;i++)
	{
		ans+=((ll)a[i]+(ll)b[i]+(ll)max(a[i],k));
	}
	for(int i=l+1;i<=l_;i++)
	{
		ans+=((ll)c[i]);
	}
	printf("%lld",ans);
	return 0;
}