#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void dfs(int n,int r,int step,bool book[],int choise[])
{
	if(step==r+1)
	{
		for(int i=1;i<=r;i++)
		{
			//[2]:
			if(i!=1)
				printf(" ");
			printf("%d",choise[i]);
		}
		printf("\n");
		return;
	}
	int i=1;
	for(;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			choise[step]=i;
			//[2] printf("%d ",choise[i]);
			dfs(n,r,step+1,book,choise);
			//[1]:
			book[i]=0;
			choise[step]=0;
		}
	}
	//[1]:
	//i--;
	//book[i]=0;
	//choise[step]=0;
}

int main()
{
	int n=0,r=0;
	scanf("%d %d",&n,&r);
	bool b[n+1];
	int c[r+1];
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	dfs(n,r,1,b,c);
	return 0;
}