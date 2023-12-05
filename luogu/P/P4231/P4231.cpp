#include <iostream>
using namespace std;

typedef unsigned long long ull;
ull a[11451419];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	ull l,r,b,e;
	for(int i=1;i<=m;i++)
	{
		scanf("%llu %llu %llu %llu",&l,&r,&b,&e);
		ull k=(e-b)/(r-l);
		a[l]+=b;
		a[l+1]+=(k-b);
		a[r+1]-=(e+k);
		a[r+2]+=e;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	ull ma=0,xs=0;
	for(int i=1;i<=n;i++)
	{
		// printf("%llu ",a[i]);
		xs^=a[i];
		ma=max(ma,a[i]);
	}
	// puts("");
	printf("%llu %llu",xs,ma);
	return 0;
}