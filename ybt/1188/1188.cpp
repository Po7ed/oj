#include <iostream>
#include <string.h>
using namespace std;
short fib[1000000];
int main()
{
	int max=2;
	memset(fib,0,sizeof(fib));
	int n;
	scanf("%d",&n);
	fib[1]=fib[2]=1;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(fib[t]!=0)printf("%d\n",fib[t]);
		else
		{
			for(int i=max+1;i<=t;i++)
			{
				fib[i]=(fib[i-2]+fib[i-1])%1000;
			}
			printf("%d\n",fib[t]);
		}
		if(t>max)max=t;
	}
	return 0;
}