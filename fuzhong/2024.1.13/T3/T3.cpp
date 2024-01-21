#include <iostream>
using namespace std;

typedef long long ll;

int get(ll x)
{
	ll tmp;
	while(x>=10)
	{
		tmp=1ll;
		while(x)tmp*=(x%10),x/=10;
		x=tmp;
	}
	return x;
}

int main()
{
	freopen("draw.in","r",stdin);
	freopen("draw.out","w",stdout);
	int T;
	ll l,r;
	scanf("%d",&T);
	int tmp,ans[10];
	while(T--)
	{
		fill(ans,ans+10,0);
		scanf("%lld %lld",&l,&r);
		for(ll i=l;i<=r;i++)ans[get(i)]++;
		for(int i=0;i<10;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0; 
}