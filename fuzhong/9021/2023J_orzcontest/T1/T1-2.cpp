#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

struct dist
{
	int d,id;
	friend inline bool operator < (dist a,dist b)
	{
		return a.d>b.d;
	}
};

ll a[114514],b[114514];
dist d[114514];
int main()
{
	freopen("round4.in","r",stdin);
	freopen("out.txt","w",stdout);
	ll n,x;
	scanf("%lld %lld",&n,&x);
	ll tmp,dis=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		tmp=a[i]%x;
		d[i].id=i;
		if(tmp<=ceil(x/2.00))
		{
			b[i]=a[i]-tmp;
			dis-=tmp;
			d[i].d=tmp;
		}
		else
		{
			b[i]=a[i]+x-tmp;
			dis+=(x-tmp);
			d[i].d=x-tmp;
		}
	}
	if(dis==0)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",b[i]);
		}
	}
	else
	{
		sort(d+1,d+(n+1));
		for(int i=1;i<=n;i++)
		{
			if(dis==0)
			{
				break;
			}
			if(dis<0&&b[i]<a[i])
			{
				b[i]+=x;
				dis+=x;
			}
			else if(dis>=0&&a[i]<b[i])
			{
				b[i]-=x;
				dis-=x;
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",b[i]);
		}
	}
	return 0;
}