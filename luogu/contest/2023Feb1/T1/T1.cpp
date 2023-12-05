#include <iostream>
using namespace std;

int main()
{
	int t,n,m,k;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d %d",&n,&k,&m);
		if(n==1)
		{
			puts("-1");
			continue;
		}
		if(k<=m)
		{
			printf("%d ",k);
			for(int j=1;j<n;j++)
			{
				printf("0 ");
			}
			puts("");
		}
		else
		{
			int kk=k,c=0;
			while(kk!=1)
			{
				c++;
				kk>>=1;
			}
			int x=1<<c,y=k^x;
			// if(x^y==k)
			if(x>m)
			{
				puts("-1");
				continue;
			}
			printf("%d %d ",x,y);
			for(int j=2;j<n;j++)
			{
				printf("0 ");
			}
			puts("");
		}
	}
	return 0;
}