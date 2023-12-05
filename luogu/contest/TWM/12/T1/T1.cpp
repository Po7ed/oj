#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n-1;i++)
	{
		if(a[i-1]<a[i]&&a[i+1]<a[i])
			ans++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			bool f=true;
			for(int k=i;k<=j;k++)
			{
				if(a[k]!=a[i])
				{
					f=false;
					break;
				}
			}
			// if(f&&(i!=0?a[i-1]<a[i]:1)&&(j!=n-1?a[j+1]<a[i]:1)&&!(i==0&&j==n-1))
			if(f&&(i!=0?a[i-1]<a[i]:0)&&(j!=n-1?a[j+1]<a[i]:0))
				ans++;
		}
	}
	printf("%d",ans);
	return 0;
}