#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll a[114514];
int main()
{
	// freopen("round4.in","r",stdin);
	// freopen("out.txt","w",stdout);
	ll n,x;
	scanf("%lld %lld",&n,&x);
	ll s=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		s+=a[i];
	}
	ll avg=(s/n)-(s/n)%x,d=s-avg*n,num=d/x,tmp;
	// printf("%lld %lld %lld\n",avg,d,num);
	for(int i=1;i<=n;i++)
	{
		tmp=(1.00*abs(a[i]-avg)/x);
		if(num==0)
		{
			tmp=0;
		}
		else if(num<tmp)
		{
			tmp=num;
			num=0;
		}
		else
		{
			num-=tmp;
		}
		printf("%lld ",avg+x*tmp);
	}
	/* for(int i=1;i<=n;i++)
	{
		printf("%lld ",avg+(i<=num?x:0));
	} */
	return 0;
}