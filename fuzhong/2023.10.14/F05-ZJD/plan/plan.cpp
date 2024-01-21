#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N=1145141;
int n;
ll a[N],b[N];

int main()
{
	// freopen("plan.in","r",stdin);
	// freopen("plan.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		b[i]=a[i]+i-1;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<n;i++)
	{
		if(b[i]==b[i+1])
		{
			puts("orz");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",b[i]-i+1);
	}
	return 0;
}
