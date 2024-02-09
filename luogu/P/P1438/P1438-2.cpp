#include <iostream>

constexpr int N=114514;

typedef long long ll;
int n;

namespace exbit
{
	ll d1[N],d2[N];
	#define lb (x&-x)
	void init(int *a,ll *d) // init a[] to d[]
	{for(int x=1;x<=n;x++)d[x]+=a[x],(x+lb<=n)&&(d[x+lb]+=d[x]);}
	inline void build(int *a) // build tree
	{for(int i=n;i;i--)a[i]-=a[i-1];exbit::init(a,d1);
	for(int i=1;i<=n;i++)a[i]*=i;exbit::init(a,d2);}
	void modify_(int x,ll y){ll t=x*y;for(;x<=n;x+=lb)d1[x]+=y,d2[x]+=t;} // [x,n]+=y
	inline void modify(int l,int r,ll y){modify_(l,y),modify_(r+1,-y);} // [l,r]+=y
	inline void modify(int x,ll y){modify_(x,y),modify_(x+1,-y);} // [x]+=y
	ll query(int x,ll *d=d1){ll res=0;for(;x;x-=lb)res+=d[x];return res;} // [x]
	inline ll query_(int x){return (x+1)*query(x)-query(x,d2);} // [1,x]
	inline ll query(int l,int r){return query_(r)-query_(l-1);} // [l,r]
} // namespace exbit

int m,a[N];

int main()
{
	// freopen("P1438_1.in","r",stdin);
	// freopen("out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	// exbit::build(a);
	int o,l,r,k,d,p;
	// for(int i=1;i<=n;i++)
	// {
	// 	printf("%d %lld\n",i,exbit::query(1,i));
	// }
	// int t=m;
	while(m--)
	{
		scanf("%d",&o);
		if(o-1)
		{
			scanf("%d",&p);
			printf("%lld\n",exbit::query(1,p)+a[p]);
		}
		else
		{
			scanf("%d %d %d %d",&l,&r,&k,&d);
			exbit::modify(l,k);
			if(l<r)exbit::modify(l+1,r,d);
			if(r<n)exbit::modify(r+1,-k-(r-l)*d);
		}
	}
	return 0;
}
