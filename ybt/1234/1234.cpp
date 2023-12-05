#include <iostream>
#include <string.h>
using namespace std;

int half(int (&a)[201])
{
	for(int i=0;1;i++)
	{
		if(a[i+1]!=-1)
		{
			a[i+1]+=a[i]%2*10;
			a[i]/=2;
		}
		else
		{
			int t=a[i]%2;
			a[i]/=2;
			return t;
		}
	}
}
int mod(int (&a)[201])
{
	int i=0;for(;a[i]!=-1;i++);i--;
	bool b=true;
	if(a[i]!=1)b=false;
	for(int j=i-1;j>=0;j--)
		if(a[j]!=0)b=false;
	if(b)return 2011;
	int t=half(a);
	/* int ta[201];
	memcpy(ta,a,sizeof(a)); */
	int ma=mod(a);
	/* ta[i]+=t;
	for(int ii=i;ii>=0;ii--)
		if(ta[ii]>9)ta[ii]%=10,ta[i-1]++;
	int mapt=mod(ta); */
	if(t)return ma*ma%10000*2011%10000;
	return ma*ma%10000;
}
int main()
{
	/* int ta[201]={2,8,-1};
	cout<<mod(ta)<<endl;
	return 0;
	43524563567363654643657 */
	int k=0;
	scanf("%d",&k);
	char ts[201];
	int a[201];
	for(int i=0;i<k;i++)
	{
		memset(a,0,sizeof(a));
		scanf("%s",&ts);
		int len=strlen(ts);
		for(int j=0;j<len;j++)
			a[j]=ts[j]-48;
		a[len]=-1;
		cout<<mod(a)<<endl;
	}
	return 0;
}