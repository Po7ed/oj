#include <cstdio>
int main()
{
	freopen("tmp","r",stdin);
	freopen("tmp2","w",stdout);
	int t;
	for(int i=1;i<=200;i++)
	{
		scanf("%d",&t);
		printf("%d %d\n",i,t);
	}
	return 0;
}