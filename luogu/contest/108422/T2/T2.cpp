#include <iostream>
using namespace std;
int main()
{
	int n,t,lt;
	scanf("%d",&n);
	bool isdb=true,isdc=true;
	int gc;
	double gb;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(i)
		{
			if(i==1)
			{
				gc=t-lt;
				gb=(double)t/lt;
			}
			else
			{
				if(gc!=t-lt)
				{
					isdc=false;
				}
				if(gb!=(double)t/lt)
				{
					isdb=false;
				}
			}
		}
		lt=t;
	}
	if(isdc)
	{
		if(isdb)
		{
			printf("doushi\n%d %lf",gc,gb);
		}
		else
		{
			printf("dengcha\n%d",gc);
		}
	}
	else
	{
		if(isdb)
		{
			// int a[1000000];
			printf("dengbi\n%lf",gb);
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}