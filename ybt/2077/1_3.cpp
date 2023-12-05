#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void getfrt(int a[][2],int n)
{
	printf("\n%d\n",n);
	if(n==0)
		return;
	int t[n+1][2],k=1;
	a[0][0]=-1;
	a[0][1]=0;
	//memset(t,-1,sizeof(t));
	bool bf=1;
	int tn=n;
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
			bf=0;
			tn--;
		}
	}
	printf("\n");
	//printf("\n%d\n%d\n",tn,k);
	getfrt(t,tn);
}

int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n+1][2];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		a[i][1]=i;
	}
	getfrt(a,n);
	return 0;
}