#include <iostream>

// #define s(i) (1+i)*i/2
#define sum(i,j) (i+j)*(j-i+1)/2

using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		// if(n%i==0&&((n/i)&1)&&(i-n/i/2)>=0&&(i+n/i/2)<=n)
		if((i-n/i/2)>=0&&(i+n/i/2)<=n&&sum((i-n/i/2),(i+n/i/2))==n)
		{
			printf("%d %d\n",i-n/i/2,i+n/i/2);
		}
		if((i-2*n/(2*i+1)/2+1)>=0&&(i+2*n/(2*i+1)/2)<=n&&sum((i-2*n/(2*i+1)/2+1),(i+2*n/(2*i+1)/2))==n)
		{
			printf("%d %d\n",i-n*2/(2*i+1)/2+1,i+n*2/(2*i+1)/2);
		}
	}
	return 0;
}
// sum()