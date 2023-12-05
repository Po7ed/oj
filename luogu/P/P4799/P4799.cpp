#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int N=45;
int n;
ll m,a[N];
vector<ll> x,y;

int main()
{
	scanf("%d %lld",&n,&m);
	int m1=n/2,m2=n-m1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	ll sum;
	for(int i=0;i<(1<<m1);i++)
	{
		sum=0;
		for(int j=0;j<m1;j++)
		{
			if((i>>j)&1)
			{
				sum+=a[j+1];
			}
		}
		x.push_back(sum);
	}
	for(int i=0;i<(1<<m2);i++)
	{
		sum=0;
		for(int j=0;j<m2;j++)
		{
			if((i>>j)&1)
			{
				sum+=a[j+m1+1];
			}
		}
		y.push_back(sum);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	ll ans=0;
	int lx=x.size(),pos;
	for(int i=0;i<lx;i++)
	{
		pos=upper_bound(y.begin(),y.end(),m-x[i])-y.begin();
		ans+=pos;
		// printf("*%lld\n",pos);
	}
	printf("%lld",ans);
	return 0;
}