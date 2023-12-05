#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int u=0,v=n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=((a[v]-a[u])*(a[v]-a[u]));
		if(i&1)
		{
			u++;
		}
		else
		{
			v--;
		}
	}
	printf("%lld",ans);
	return 0;
}