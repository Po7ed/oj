#include <iostream>
#include <algorithm>
using namespace std;

struct l
{
	int v,id;
};

bool cmp(l a,l b)
{
	return (a.v==b.v?a.id<b.id:a.v<b.v);
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	l a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i].id);
	}
	return 0;
}