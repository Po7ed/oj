#include <iostream>

typedef long long ll;
int n,m;
constexpr int N=114514;
int a[N];

namespace bit
{
	#define lb (x&-x)
	namespace _bit // use c -> cc
	{
		ll c[N]; // c[i]=cc[i-lb(i)+1]+...+cc[i]
		void modify(int x,int y) // cc[x]+=y
		{
			for(;x<=n;x+=lb)
			{
				c[x]+=y;
			}
		}
		ll query(int x) // C[x]=c[1]+...+c[x]
		{
			ll res=0;
			for(;x;x-=lb)
			{
				res+=c[x];
			}
			return res;
		}
		void modify(int l,int r,int k,int d) // shell to modify cc
		{
			modify(l,k),modify(l+1,d-k);
			modify(r+1,-k-(r-l+1)*d),modify(r+2,k+(r-l)*d);
		}
	} // namespace _bit
	ll b[N];
	ll query(int x) // 
	{
		ll res=0;
		for(int i=1;i<=x;i++)
		{
			res+=_bit::query(i);
		}
		return res;
	}
} // namespace bit

int main()
{
	// freopen("P1438_1.in","r",stdin);
	// freopen("out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int o,l,r,k,d,p;
	while(m--)
	{
		// printf("%d:",m);for(int i=1;i<=n+3;i++)printf("%lld ",bit::_bit::query(i));
		// puts("");
		scanf("%d",&o);
		if(o-1)
		{
			scanf("%d",&p);
			printf("%lld\n",bit::query(p)+a[p]);
		}
		else
		{
			scanf("%d %d %d %d",&l,&r,&k,&d);
			bit::_bit::modify(l,r,k,d);
		}
	}
	return 0;
}
