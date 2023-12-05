#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

typedef long long ll;
constexpr int N=114514;
int n,m;
ll a[N];

namespace dset
{
	int f[N];
	inline void init(){iota(f,f+N,0);}
	int find(int x){return (f[x]==x?x:f[x]=find(f[x]));}
}//^ namespace dset
namespace bitr
{
	#define lb ((-x)&x)
	ll bit[N];
	inline void modify(int x,ll y)
	{
		for(;x<=n;x+=lb){bit[x]+=y;}
	}
	inline void init()
	{
		for(int i=1;i<=n;i++)
		{
			modify(i,a[i]);
		}
	}
	inline ll query(int x)
	{
		ll res=0;
		for(;x;x-=lb){res+=bit[x];}
		return res;
	}
}//^ namespace bitr

int main()
{
	dset::init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	bitr::init();
	scanf("%d",&m);
	for(int i=1,o,l,r;i<=m;i++)
	{
		scanf("%d %d %d",&o,&l,&r);
		if(r<l)swap(l,r);
		if(o)
		{
			printf("%lld\n",bitr::query(r)-bitr::query(l-1));
		}
		else
		{
			for(int j=l,t;j<=r;j=(dset::f[j]==j?j+1:dset::find(j)))
			{
				t=sqrt(a[j]);
				bitr::modify(j,t-a[j]);a[j]=t;
				if(t==1)dset::f[j]=j+1;
			}
		}
	}
	return 0;
}