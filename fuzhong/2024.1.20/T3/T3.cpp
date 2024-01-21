#include <iostream>
using namespace std;

constexpr int N=114514;
// int a[N];

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		printf("%d ",n);
		for(int i=1;i<=m&&i<=n-1;i++)printf("%d ",i);
		for(int i=n-1;i>m;i--)printf("%d ",i);
		puts("");
	}
	return 0;
}
