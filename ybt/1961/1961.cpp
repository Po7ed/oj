#include <iostream>
using namespace std;
int main()
{
	int x,r,c=0;
	scanf("%d %d",&r,&x);
	for(int i=1;i<=r;i++)
	{
		if(i>=0)if(i%10==x)c++;
		if(i>=10)if(i/10%10==x)c++;
		if(i>=100)if(i/100%10==x)c++;
		if(i>=1000)if(i/1000%10==x)c++;
		if(i>=10000)if(i/10000%10==x)c++;
		if(i>=100000)if(i/100000%10==x)c++;
		if(i>=1000000)if(i/1000000%10==x)c++;
	}
	printf("%d",c);
	return 0;
}