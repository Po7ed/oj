#include <iostream>
using namespace std;

typedef long long ll;
const int N=300005;
int n,k;
ll ans,arr[N],ccf[N],s[N],ss[N];

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",arr+i);
	}
	for(int i=n;i>0;i--)
	{
		int pos=max(1,i-k+1),len=i-pos+1;
		ll times=(arr[i]+len-1)/len;// ceil
		if(times>0)
		{
			ans+=times;
			ccf[pos]-=times;
			ccf[i+1]+=(times*(k+1));
		}
		s[i]=s[i+1]+ccf[i]+(times>0?k*times+1:0);
		ss[i]=ss[i+1]+s[i];
		arr[i-1]-=ss[i];
	}
	printf("%lld",ans);
	return 0;
}