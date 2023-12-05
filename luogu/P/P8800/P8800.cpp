#include <iostream>
using namespace std;
typedef long long ll;
int a[211451],b[211451];
int n;
ll m;

bool check(int x)
{
	ll tm=m;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)
		{
			if(x-a[i]>b[i])
			{
				// printf("oops:%d\n",i);
				return false;
			}
			else
			{
				tm-=(x-a[i]);
				if(tm<0)
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d %lld",&n,&m);
	int mia=0x3f3f3f3f,miab=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		mia=min(mia,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",b+i);
		miab=min(miab,a[i]+b[i]);
	}
	int l=mia,r=miab,ans;
	// printf("%d %d\n",mia,miab);
	#define mid ((l+r)>>1)
	while(l<=r)
	{
		// printf("%d %d %d\n",l,mid,r);
		if(check(mid))
		{
			// puts("OK");
			ans=mid;
			l=mid+1;
		}
		else
		{
			// puts("NO");
			r=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}