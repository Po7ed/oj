#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

struct l
{
	ll v,w;
	int id;
};

bool cmp(l a,l b)
{
	return (a.v==b.v?(a.w==b.w?a.id<b.id:a.w<b.w):a.v<b.v);
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	l a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].v);
		a[i].w=a[i].v*i;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i].id);
	}
	return 0;
}