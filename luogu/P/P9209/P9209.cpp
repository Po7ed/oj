#include <iostream>
using namespace std;

typedef long long ll;
const int N=114514;
ll w[N],l[N],r[N],ans;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",w+i);
	for(int i=1;i<=n;i++)scanf("%lld",l+i);
	for(int i=1;i<=n;i++)scanf("%lld",r+i);
	for(int i=1;i<=n;i++)ans+=(w[i]-(n-i)*max(l[i],r[i]));
	printf("%lld",ans);
	return 0;
}
