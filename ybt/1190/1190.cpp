#include <iostream>
#include <string.h>
using namespace std;
int a[71]={0};
int main()
{
	// freopen("out.txt","w",stdout);
	memset(a,0,sizeof(a));
	a[1]=1;a[2]=2;a[3]=4;
	int t;
	while(scanf("%d",&t)&&t!=0)
	{
		for(int i=4;i<=t;i++)
		{
			if(a[i]!=0)continue;
			a[i]=a[i-3]+a[i-2]+a[i-1];
		}
		printf("%d\n",a[t]);
	}
	return 0;
}