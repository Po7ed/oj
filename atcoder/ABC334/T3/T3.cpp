#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=214514;
int a[N];
int n,m;

ll pre[N],suf[N];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	ll ans=0;
	if(!(m&1))
	{
		for(int i=1;i<=m;i+=2)
		{
			ans+=ll(abs(a[i]-a[i+1]));
		}
	}
	else
	{
		for(int i=2;i<=m;i+=2)
		{
			pre[i]=pre[i-2]+ll(abs(a[i]-a[i-1]));
		}
		for(int i=m-1;i>0;i-=2)
		{
			suf[i]=suf[i+2]+ll(abs(a[i]-a[i+1]));
		}
		ans=0x3f3f3f3f3f3f3f3f;
		ll tmp;
		for(int i=1;i<=m;i++)
		{
			if(i&1)
			{
				tmp=pre[i-1]+suf[i+1];
			}
			else
			{
				tmp=pre[i-2]+suf[i+2]+ll(abs(a[i-1]-a[i+1]));
			}
			ans=min(ans,tmp);
		}
	}
	printf("%lld",ans);
	return 0;
}