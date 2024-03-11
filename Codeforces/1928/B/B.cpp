#include <iostream>
#include <algorithm>
using std::sort;
using std::max;
using std::upper_bound;
using std::unique;
constexpr int N=214514;
int a[N],n,tn;
int main()
{
	// freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		sort(a+1,a+n+1);
		tn=unique(a+1,a+n+1)-a-1;
		int /* cnt=1, */ans=1,j;
		for(int i=1;i<=tn;i++)// l
		{
			j=upper_bound(a+1,a+tn+1,a[i]+n-1)-a-1;
			ans=max(ans,j-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}