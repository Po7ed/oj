#include <iostream>
using namespace std;

unsigned long long ans;
void ms(int b,int e,int ar[]);

int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n];
	for(int c=0;c<n;c++)
		scanf("%d",&a[c]);
	ms(0,n-1,a);
	printf("%llu",ans);
	return 0;
}

void ms(int b,int e,int ar[])
{
	if(b==e)return;
	int t[e-b+1],m=(b+e)/2;
	ms(b,m,ar);ms(m+1,e,ar);
	int i=b,j=m+1;
	int c=0;
	while(i<=m&&j<=e)
	{
		if(ar[i]<=ar[j])
		{
			t[c]=ar[i];
			i++;
		}
		else
		{
			t[c]=ar[j];
			j++;
			ans+=(m-i+1);
		}
		c++;
	}
	if(i>m)
		for(;j<=e;j++)
		{
			t[c]=ar[j];
			c++;
		}
	else
		for(;i<=m;i++)
		{
			t[c]=ar[i];
			c++;
		}
	for(int cc=b;cc<=e;cc++)
		ar[cc]=t[cc-b];
}