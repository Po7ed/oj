#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],f[n],g[n];
	f[0]=1;
	g[n-1]=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
		{
			f[i]=f[i-1]+1;
		}
		else
		{
			f[i]=1;
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		if(a[i+1]>a[i])
		{
			g[i]=g[i+1]+1;
		}
		else
		{
			g[i]=1;
		}
	}
	int ans=g[1]+1;
	for(int i=1;i<n-1;i++)
	{
		ans=max(ans,(a[i+1]-1>=a[i-1]+1?g[i+1]+1+f[i-1]:max(g[i+1]+1,f[i-1]+1)));
	}
	ans=max(ans,f[n-2]+1);
	printf("%d",(n==1?1:ans));
	// printf("%d",n);
	return 0;
}