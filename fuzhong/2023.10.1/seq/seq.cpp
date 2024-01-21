#include <iostream>
#include <algorithm>
using namespace std;

const int mod=10007,N=114514;
int a[N],ta[N],last[N],cnt[N],pow[N];
int ans1,ans2;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		ta[i]=a[i];
	}
	pow[0]=1;
	for(int i=1;i<=n;i++)
	{
		pow[i]=(pow[i-1]<<1)%mod;
	}
	sort(ta+1,ta+n+1);
	int m=unique(ta+1,ta+n+1)-ta-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(ta+1,ta+m+1,a[i])-ta;
		ans1+=(pow[n-1-cnt[a[i]]]);
		ans1%=mod;
		cnt[a[i]]++;
		ans2+=(1ll*(i-last[a[i]])*(n-i+1)%mod);
		ans2%=mod;
		last[a[i]]=i;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}