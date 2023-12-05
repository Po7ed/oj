#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

struct thing
{
	ll v,id;
};
inline bool cmp(thing x,thing y)
{
	return x.v>y.v;
}
inline bool cmpback(thing x,thing y)
{
	return x.id<y.id;
}

ll a[114514],b[114514];
thing c[114514];
int main()
{
	freopen("round.in","r",stdin);
	freopen("round.out","w",stdout);
	ll n,x;
	scanf("%lld %lld",&n,&x);
	ll m,sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		c[i].v=a[i]%x;
		c[i].id=i;
		sum+=c[i].v;
	}
	m=sum/x;
	sort(c+1,c+(n+1),cmp);
	for(int i=1;i<=m;i++)
	{
		b[c[i].id]=x;
	}
	sort(c+1,c+(n+1),cmpback);
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",a[i]-c[i].v+b[i]);
	}
	return 0;
}