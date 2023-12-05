#include <iostream>
using namespace std;
int main()
{
	long long x,y,z;
	scanf("%lld %lld %lld",&x,&y,&z);
	long long bug[z+1],egg[z+1];
	for(int i=0;i<=x;i++)bug[i]=1,egg[i]=0;
	for(int i=x+1;i<=z+1;i++)
	{
		bug[i]=bug[i-1]+egg[i-2];
		egg[i]=bug[i-x]*y;
	}
	printf("%lld",bug[z+1]);
	return 0;
}