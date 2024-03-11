#include <iostream>
#include <vector>

typedef long long ll;
constexpr int N=114514;
int a[N],n;
int pre[N],nxt[N];

int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		std::vector<int> v(1,0);
		a[0]=a[n+1]=-1;
		for(int i=1;i<=n;i++)
		{
			while(a[v.back()]>=a[i])v.pop_back();
			pre[i]=v.back();
			v.push_back(i);
		}
		v={n+1};
		for(int i=n;i;i--)
		{
			while(a[v.back()]>=a[i])v.pop_back();
			nxt[i]=v.back();
			v.push_back(i);
		}
		ll ans=-1;
		for(int i=1;i<=n;i++)
		{
			ans=std::max(ans,1ll*(nxt[i]-pre[i]-1)*a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}