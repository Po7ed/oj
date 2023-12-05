#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int k=1,t=0,n=0,min=1001;
	bool book=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(t<=min)
			min=t;
		else
		{
			if(book)
			{
				book=0;
				printf("%d ",i);
			}
			k++;
		}
	}
	printf("%d",k);
	return 0;
}