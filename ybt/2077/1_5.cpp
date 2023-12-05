#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void getfrt(int a[][2],int n)
{
	if(n==0)
		return;
		
	int k=1;
	bool bf=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1][0]==a[i][0])//保留
		{
			a[k][0]=a[i][0];
			a[k][1]=a[i][1];
			k++;
			continue;
		}
		else//取走
		{
			if(bf==0)
				printf(" ");
			printf("%d",a[i][1]);
			bf=0;
		}
	}
	printf("\n");
	k--;
	getfrt(a,k);
	
}

int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n+1][2];
	a[0][0]=-1;
	for(int i=1;i<=n;i++)
	{
		
		scanf("%d",a[i]+0);
		a[i][1]=i;
	}
	
	getfrt(a,n);//[1]
	return 0;
}