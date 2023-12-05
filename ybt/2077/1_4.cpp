#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void getfrt(int a[][2],int n)
{
	//printf("\n%d\n",n);
	if(n==0)
		return;
	int t[n+1][2];
	int k=1;
	a[0][0]=-1;
		//memset(t,-1,sizeof(t));
	bool bf=1;
	//int tn=n;//[1]
	for(int i=1;i<=n;i++)
	{
		if(a[i-1][0]==a[i][0])//保留
		{
			t[k][0]=a[i][0];
			t[k][1]=a[i][1];
			k++;
			continue;
		}
		else//取走
		{
			if(bf==0)
				printf(" ");
			printf("%d",a[i][1]);
				//cout<<" "<<flush;
			//cout<<a[i][1]<<flush;
			bf=0;
			//tn--;//[1]
			//[1] n--;
		}
	}
	printf("\n");
	//printf("\n%d\n%d\n",tn,k);
	k--;
	
	getfrt(t,k);
	
}

int main()
{
	int n=0;
	scanf("%d",&n);
	//cin>>n;
	int aaa[n+1][2];//
	//int ttt[n+1][2];//
	
	for(int i=1;i<=n;i++)
	{
		
		scanf("%d",&aaa[i][0]);
		//cin>>a[i][0];
		aaa[i][1]=i;
	}
	getfrt(aaa,n);//[1]
	//[1] getfrt(t,n);
	return 0;
}