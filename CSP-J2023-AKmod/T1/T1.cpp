#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("world.in","r",stdin);
	freopen("world.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int m;
	scanf("%d",&m);
	sort(a+1,a+(n+1));
	int *p=nullptr;
	for(int i=1;i<=n;i++)
	{
		p=lower_bound(a+1,a+(n+1),m-a[i]);
		if(*p+a[i]==m)
		{
			printf("%d %d",min(*p,a[i]),max(*p,a[i]));
			return 0;
		}
	}
	puts("No");
	return 0;
}