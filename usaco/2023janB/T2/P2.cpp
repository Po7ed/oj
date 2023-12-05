#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	int n,m;//1+
	scanf("%d %d",&n,&m);
	int s[n+1],t[n+1],c[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&s[i],&t[i],&c[i]);
	}
	int a[m+1],b[m+1],q[m+1],p[m+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&a[i],&b[i],&p[i],&q[i]);
	}
	int l=pow(2,m);
	int qi;
	int x[101];
	int ans=0x3f3f3f3f;
	for(int i=0;i<l;i++)//each case for aircon.
	{
		qi=0;
		memset(x,0,sizeof(x));
		for(int j=1;j<=m;j++)//each aircon.
		{
			if((i>>(j-1))&1)
			{
				qi+=q[j];
				for(int k=a[j];k<=b[j];k++)//each aircon.'s place
				{
					x[k]+=p[j];
				}
			}
		}
		bool f=true;
		for(int j=1;j<=n;j++)//each cow
		{
			for(int k=s[j];k<=t[j];k++)//each cow's place
			{	
				if(x[k]<c[j])
					f=false;
			}
		}
		if(f)
		{
			ans=min(ans,qi);
		}
	}
	printf("%d",ans);
	return 0;
}