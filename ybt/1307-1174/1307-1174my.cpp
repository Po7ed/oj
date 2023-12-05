#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int a[202],b[202],c[404];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	string ta,tb;
	cin>>ta>>tb;
	for(int i=0;i<ta.length();i++)
		a[ta.length()-i-1]=ta[i]-48;
	for(int i=0;i<tb.length();i++)
		b[tb.length()-i-1]=tb[i]-48;
	for(int i=0;i<ta.length();i++)
	{
		for(int j=0;j<tb.length();j++)
		{
			c[i+j]=a[i]*b[j]+c[i+j];
			if(c[i+j]>=10)
			{
				c[i+j+1]+=c[i+j]/10;
				c[i+j]%=10;
			}
		}
	}
	int lc=ta.length()+tb.length();
	while(c[lc]==0&&lc>=1)
		lc--;
	for(int i=lc;i>=0;i--)
		cout<<c[i]<<flush;
	return 0;
}