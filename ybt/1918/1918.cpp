#include <iostream>
using namespace std;

int main()
{
	int k;
	scanf("%d",&k);
	int i=1;
	double s=0;
	for(;s<=k;i++)
	{
		s+=(1.00/i);
	}
	printf("%d",--i);
	return 0;
}