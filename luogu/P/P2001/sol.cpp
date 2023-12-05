#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll a[200114];
#ifdef input_with_read
#include <cctype>
int read()
{
	int f=1,res;
	char c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
		if(c=='-')
		{
			f*=-1;
		}
	}
	while(isdigit(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
#endif

int main()
{
	int n;
	ll m;
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	a[n+1]=m;
	sort(a+1,a+(n+1));
	if(a[1]!=1)
	{
		puts("No answer!!!");
		return 0;
	}
	ll now=0,ans=0/* ,k */;
	ll k=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]-1>now)
		{
			k=min((a[i+1]-2-now),(m-2-now))/a[i]+1;
			now+=k*a[i];
			ans+=k;
			//ans++;
			//now+=a[i];
			if(now>=m)
			{
				printf("%lld",ans);
				return 0;
			}
		}
	}
	printf("%lld",ans+1);
	return 0;
}