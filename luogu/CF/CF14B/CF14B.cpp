#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,x;
	scanf("%d %d",&n,&x);
	int a,b,l=-0x3f3f3f3f,r=0x3f3f3f3f;
	int s[4];
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
		{
			swap(a,b);
		}
		if(b<l||r<a)
		{
			puts("-1");
			return 0;
		}
		s[0]=a;
		s[1]=b;
		s[2]=l;
		s[3]=r;
		sort(s,s+4);
		l=s[1];
		r=s[2];
	}
	if(l<=x&&x<=r)
	{
		puts("0");
	}
	else if(x<l)
	{
		printf("%d\n",l-x);
	}
	else
	{
		printf("%d\n",x-r);//想当然（r-x）
	}
	return 0;
}