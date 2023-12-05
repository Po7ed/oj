#include <stdio.h>
#include <cmath>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int n=0,p[601];
	memset(p,0,sizeof(p));
	short w=0;
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int t=0,sum=0;
		scanf("%d",&t);
		p[t]++;
		int j=600;
		for(;sum<(1>=(int)floor(i*w/100)?1:(int)floor(i*w/100));j--)
			sum+=p[j];
		j++;
		if(i!=1)
			printf(" ");
		printf("%d",j);
	}
	return 0;
}