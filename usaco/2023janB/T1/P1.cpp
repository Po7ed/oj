#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char a[n+2];
	scanf("%s",a+1);
	int e[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&e[i]);
	}
	int gn=0,hn=0;
	// bool g[n+1],h[n+1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='G')
		{
			gn++;
		}
		else
		{
			hn++;
		}
	}
	bool gl[n+1],hl[n+1];
	int gln=0,hln=0;
	memset(gl,false,sizeof(gl));
	memset(hl,false,sizeof(hl));
	for(int k=0;k</*n/100000+*/2;k++)
	{
		for(int i=1;i<=n;i++)
		{
			int tl=0;
			for(int j=i;j<=e[i];j++)
			{
				if(a[i]==a[j])
				{
					tl++;
				}
				if(a[i]=='G'&&hl[j])
				{
					if(gl[i]==false)
						gln++;
					gl[i]=true;
				}
				if(a[i]=='H'&&gl[j])
				{
					if(hl[i]==false)
						hln++;
					hl[i]=true;
				}
			}
			if(a[i]=='G'&&tl==gn)
			{
				if(gl[i]==false)
					gln++;
				gl[i]=true;
			}
			if(a[i]=='H'&&tl==hn)
			{
				if(hl[i]==false)
					hln++;
				hl[i]=true;
			}
		}
	}
	// printf("*%d;%d\n",gln,hln);
	printf("%d",gln*hln);
	return 0;
}