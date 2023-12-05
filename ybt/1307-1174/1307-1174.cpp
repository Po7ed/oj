#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int a[101],b[101],c[10001],x=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	char ta[101],tb[101];
	scanf("%s",ta);
	scanf("%s",tb);
	int lena=strlen(ta),lenb=strlen(tb),lenc=0;
	for(int i=0;i<=lena-1;i++)
		a[lena-i]=ta[i]-48;
	for(int i=0;i<=lenb-1;i++)
		b[lenb-i]=tb[i]-48;
	for(int i=1;i<=lena;i++)
	{
		x=0;
		if(a[i]==0)
			continue;
		for(int j=1;j<=lenb;j++)
		{
			if(b[j]==0)
				continue;
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+lenb]=x;
	}
	lenc=lena+lenb;
	while(c[lenc]==0&&lenc>1)
		lenc--;
	for(int i=lenc;i>=1;i--)
		cout<<c[i]<<flush;
	return 0;
}