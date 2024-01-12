#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;
constexpr int N=214514;
ll a[N],b[N];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=m;i++)scanf("%lld",b+i);
	ll lst,cpy;
	for(int j=1;j<=m;j++)
	{
		lst=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=b[j]){a[i]+=(b[j]-lst);break;}
			if(a[i]>=lst)cpy=a[i],a[i]+=(a[i]-lst),lst=cpy;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld\n",a[i]);
	}
	return 0;
}