#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		unsigned long long a[n+1];
		int c[n+1];
		for(int j=1;j<=n;j++)
		{
			scanf("%llu",&a[j]);
		}
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[j]);
		}
		if(c[1]==c[n])
		{
			printf("%lld\n",a[1]+a[n]);
		}
		else
		{
			unsigned long long m=0x3f3f3f3f3f3f;
			for(int j=1;j<n;j++)
			{
				if(c[1]==c[j]&&c[j+1]==c[n])
				{
					m=min(m,a[1]+a[j]+a[j+1]+a[n]);
				}
			}
			printf("%llu\n",m);
		}
	}
	return 0;
}