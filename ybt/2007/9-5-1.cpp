#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int n=0,m=0;
	scanf("%d %d",&n,&m);

	long long int board[n+2][m+1];
	long long int sum[n+2][2];
	long long int sum1[n+2][2];//�ӱ������Ϻ����ҷ����е����ֵ
	long long int sum2[n+2][2];//�ӱ������·�������ֵ
	long long int ms=-10000000000000000;


	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&board[i][j]);
		}

	for(int j=0;j<=1;j++)
		for(int i=0;i<=n+1;i++)
		{
		sum[i][j]=ms;
		sum1[i][j]=ms;
		sum2[i][j]=ms;
		}
	sum[n][1]=board[n][m];

	for(int i=n-1;i>=1;i--)//��ֵ��j��
	{
		sum[i][1]=sum[i+1][1]+board[i][m];
	}
	for(int j=1;j<=m;j++)//��ֵ
	{
		board[0][j]=ms;
		board[n+1][j]=ms;
	}

	for(int j=m-1;j>=1;j--)//��ʼѭ��
	{
//cout<<"----"<<j<<endl;	
		for(int i=1;i<=n;i++)//���㱾�����Ϻ� �ҷ���Ĵ�ֵ
		{
			if (sum1[i-1][0]>=sum[i][1])
			{
				sum1[i][0]=board[i][j]+sum1[i-1][0];
			}
			else sum1[i][0]=board[i][j]+sum[i][1];

// cout<<sum1[i][0]<<endl;
		}	
// cout<<endl;
		for(int i=n;i>=1;i--)//�������·���Ĵ�ֵ
		{
			if (sum2[i+1][0]>=sum[i+1][1]+board[i+1][j])
			{
				sum2[i][0]=board[i][j]+sum2[i+1][0];
			}
			else sum2[i][0]=board[i][j]+board[i+1][j]+sum[i+1][1];

//cout<<sum2[i][0]<<endl;

		}	
//cout<<endl;
		for(int i=1;i<=n;i++)
		{
			if (sum1[i][0]<=sum2[i][0])sum[i][0]=sum2[i][0];
			else sum[i][0]=sum1[i][0];
//cout<<sum[i][0]<<endl;

		}	
//cout<<endl;

		for(int i=1;i<=n;i++)
		{
		sum[i][1]=sum[i][0];
		}

//cout<<j<<"----"<<endl;		
	}

	printf("%lld",sum[1][0]);
	return 0;
}

/*
3 4
1 -1 3 2
2 -1 4 -1
-2 2 -3 -1
*/