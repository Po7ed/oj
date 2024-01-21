#include <iostream>
using namespace std;

constexpr int N=114514;
int a[N];

int gcd(int a,int b){return (b?gcd(b,a%b):a);}

int main()
{
	int n,g;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	g=gcd(a[1],a[2]);
	if(n==2)
	{
		if(g==a[1])
		{
			printf("0 1");
		}
		else if(g==a[2])
		{
			printf("2 0");
		}
		else
		{
			printf("-1");
		}
	}
	else
	{
		printf("-1");
	}
	return 0;
}