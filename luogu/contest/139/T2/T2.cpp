#include <iostream>
// #include <vector>
// #include <queue>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		int a[n+1],c[n+1]/* ,f1q[n+1] */;
		double f1[n+1];
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[j]);
		}
		int m=a[1]+a[n],mm=n-1,mmm=-1;
		for(int j=1;j<=n;j++)
		{
			f1[j]=(double)j/(double)(a[1]+a[j]);
			// f1q=a[1]+a[j];
		}
		// #define k ((double)(n-j+1)/(a[n]+a[j]))
		for(int j=n-1;j>0;j--)
		{
			if(j+1<n&&f1[mm]<f1[j+1])
			{
				mm=j;
			}
			if(f1[mm]<f1[j-1])
			{
				mmm=j-1;
			}
			if(mmm!=-1)
			{
				m=min(m,a[n]+a[j]+a[mmm]+a[1]);
			}
		}
		printf("%d\n",m);
	}
	return 0;
}