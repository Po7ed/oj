#include <iostream>
using namespace std;
int main()
{
	// freopen("D:\\out.txt","w",stdout);
	int t,n;
	long long k;
	int p=0,pp=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		p=0;
		pp=0;
		scanf("%d %d",&n,&k);
		unsigned int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%u",&a[i]);
			p^=a[i];
			// p=p^a[i];
		}
		if(k&1)
		{
			for(int i=0;i<n;i++)
			{
				// a[i]=p^a[i];
				a[i]^=p;
			}
			for(int i=0;i<n;i++)
			{
				printf("%u ",a[i]);
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				// a[i]=p^a[i];
				a[i]^=p;
				pp^=a[i];
			}
			for(int i=0;i<n;i++)
			{
				// a[i]=p^a[i];
				a[i]^=pp;
			}
			for(int i=0;i<n;i++)
			{
				printf("%u ",a[i]);
			}
		}
		puts("");
	}
	return 0;
}