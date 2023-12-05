#include <iostream>
#include <algorithm>
using namespace std;

inline bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int a[n*n+1],cnt=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[cnt++]);
			// ma[j]=max(ma[j],t);
		}
	}
	sort(a+1,a+cnt,cmp);
	reverse(a+1,a+(n+1));
	int *p,t;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&t);
		p=lower_bound(a+1,a+(n+1),t);
		// printf("*p=%d\n",*p);
		if(p!=a+(n+1))
		{
			printf("%d\n",a+n+1-p);
		}
		else
		{
			puts("0");
		}
	}
	return 0;
}
