#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int d[n+114],len=0,ans=0;
	d[len++]=a[1];
	for(int i=2;i<=n;i++)//A,sBsB...
	{
		if(d[len-1]==a[i])
		{
			continue;
		}
		if(len&1)
		{
			if(d[len-1]<a[i])
			{
				d[len++]=a[i];
			}
			else
			{
				d[len-1]=a[i];
			}
		}
		else
		{
			if(d[len-1]>a[i])
			{
				d[len++]=a[i];
			}
			else
			{
				d[len-1]=a[i];
			}
		}
	}
	ans=max(ans,len);
	len=0;
	d[len++]=a[1];
	for(int i=2;i<=n;i++)//B,BsBs...
	{
		if(d[len-1]==a[i])
		{
			continue;
		}
		if(len&1)
		{
			if(d[len-1]>a[i])
			{
				d[len++]=a[i];
			}
			else
			{
				d[len-1]=a[i];
			}
		}
		else
		{
			if(d[len-1]<a[i])
			{
				d[len++]=a[i];
			}
			else
			{
				d[len-1]=a[i];
			}
		}
	}
	ans=max(ans,len);
	printf("%d",ans);
	return 0;
}