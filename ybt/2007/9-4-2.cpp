#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n=0,m=0;
	scanf("%d %d",&n,&m);

	long long int board[n+1][m+1];
	long long int sum1[n+2][m+1];
	long long int sum2[n+2][m+1];
	long long int sum3[n+2][m+1];
	long long int ms=-10000000000000000;
	long long int tmp=0;

	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&board[i][j]);
			sum1[i][j]=ms;
			sum2[i][j]=ms;
			sum3[i][j]=ms;
		}
	}
	sum1[n][m]=board[n][m];
	for(int i=n-1;i>=1;i--)
		sum1[i][m]=sum1[i+1][m]+board[i][m];

	for(int j=1;j<=m;j++)
	{
		sum1[0][j]=ms;
		sum2[0][j]=ms;
		sum3[0][j]=ms;
		sum1[n+1][j]=ms;
		sum2[n+1][j]=ms;
		sum3[n+1][j]=ms;
	}

	

	for(int j=m-1;j>=1;j--)
	{
		for(int i=1;i<=n;i++)
		{
			if (sum3[i-1][j]>=sum2[i-1][j])tmp=sum3[i-1][j];
			else tmp=sum2[i-1][j];
			sum3[i][j]=board[i][j]+tmp;

			if (sum2[i][j+1]>=sum3[i][j+1])tmp=sum2[i][j+1];
			else tmp=sum3[i][j+1];
			if (tmp<=sum1[i][j+1])tmp=sum1[i][j+1];			
			sum2[i][j]=board[i][j]+tmp;
		}	
		for(int i=n;i>=1;i--)
		{
			if (sum1[i+1][j]>=sum2[i+1][j])tmp=sum1[i+1][j];
			else tmp=sum2[i+1][j];
			sum1[i][j]=board[i][j]+tmp;
		}	
	}

	if (sum1[1][1]>=sum2[1][1])tmp=sum1[1][1];
			else tmp=sum2[1][1];
	printf("%lld",tmp);
	return 0;
}

/*
3 4
1 -1 3 2
2 -1 4 -1
-2 2 -3 -1
*/