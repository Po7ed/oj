#include <iostream>
using namespace std;

typedef long long ll;
const int N=114514;
ll a[N];

ll gcd(ll a,ll b)
{
	return (b?gcd(b,a%b):a);
}

inline ll solve(int l,int r)
{
	if(l==r)
	{
		return a[l];
	}
	int mid=(l+r)>>1,cl,cr;
	ll g=a[mid],res=0;
	cl=cr=mid;
	while(l<cl&&cr<=r)
	{
		g=gcd(g,a[--cl]);
		while(cr<r&&!(a[cr+1]%g))
		{
			cr++;
		}
		while(l<cl&&!(a[cl-1]%g))
		{
			cl--;
		}
		res=max(res,g*(cr-cl+1));
	}
	cl=cr=mid;
	g=a[mid];
	while(l<=cl&&cr<r)
	{
		g=gcd(g,a[++cr]);
		while(l<cl&&!(a[cl-1]%g))
		{
			cl--;
		}
		while(cr<r&&!(a[cr+1]%g))
		{
			cr++;
		}
		res=max(res,g*(cr-cl+1));
	}
	return max(max(solve(l,mid),solve(mid+1,r)),res);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	printf("%lld",solve(1,n));
	return 0;
}