#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void getfrt(int a[][5],int n)
{
	if(a[0][4]==n+1)
		return;

	int jumpf=1;
	int jumpb=1;
	int t=-1;
	bool bf=1;

	for(int i=0;i<=n;i=i+a[i][4])
	{
		if(a[i][0]!=t)
		{
			if(bf==0)
				printf(" ");
	 		printf("%d",a[i][1]);
			a[i][1]++;
			a[i][2]--;
			bf=0;
			t=a[i][0];
			if(a[i][2]==0)
			{
				a[i-a[i][3]][4]=a[i][4]+a[i-a[i][3]][4];
				a[i+a[i][4]][3]=a[i][3]+a[i+a[i][4]][3];
			}
		}
	}
	printf("\n");
	getfrt(a,n);
}

int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n+2][5];
	int k=1;
	int kk=1;
	a[0][0]=-1;////提前
	a[0][4]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		a[i][1]=i;
	/*	a[i][2]=1;
		a[i][3]=1;
		a[i][4]=1;*/
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]==a[i-1][0])
		{
			k++;
			a[i-k][2]++;
			a[i][2]=-1;
		}
		else
		{
			k=0;
			a[i][2]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][2]!=-1)
		{
			a[kk][0]=a[i][0];
			a[kk][1]=a[i][1];
			a[kk][2]=a[i][2];
			a[kk][3]=1;
			a[kk][4]=1;
			kk++;
		}
	}
	kk--;
	getfrt(a,kk);
	return 0;
}
