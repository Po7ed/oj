#include <iostream>
using namespace std;
int main()
{
	int n=0;
	scanf("%d",&n);
	if(n%2==1){printf("-1");return 0;}
	int x=1;
	while(x<=n)x*=2;
	x/=2;
	while(n!=0)
	{
		if(n<x){x/=2;continue;}
		n-=x;
		printf("%d ",x);
		x/=2;
	}
	return 0;
}