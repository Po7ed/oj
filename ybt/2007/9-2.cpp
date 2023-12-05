#include <iostream>
using namespace std;

/*
void dfs(int n,int m,int i,int j,int s)
{
	//cout<<i<<" "<<j<<endl;
	if(n==i&&m==j)
	{
		s+=board[i][j];
		if(s>ms)
			ms=s;
		//cout<<endl;
		return;
	}
	s+=board[i][j];
	book[i][j]=1;
	if(i>1&&book[i-1][j]==0)
		dfs(n,m,i-1,j,s);
	if(i<n&&book[i+1][j]==0)
		dfs(n,m,i+1,j,s);
	if(j<m&&book[i][j+1]==0)
		dfs(n,m,i,j+1,s);
	book[i][j]=0;
	s-=board[i][j];
	return;
}
*/
int main()
{
	int n=0,m=0;
	scanf("%d %d",&n,&m);
	bool book[n+1][m+1];
	short board[n+1][m+1];
	int sum[n+1][m+1];
	int ms=-(1E4+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&board[i][j]);
			sum[i][j]=ms;
		}
	sum[1][1]=board[1][1];
	for(int i=2;i<=n;i++)
		sum[i][1]=sum[i-1][1]+board[i][1];
	for(int j=2;j<m;j++)
	{
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
			{
				int t=0;
				if(i==k)
				{
					t=sum[i][j-1]+board[k][j];
					if(sum[k][j]<t)
						sum[k][j]=t;
				}
				if(i>k)
				{
					if(board[i][j]+sum[i][j-1]>sum[i-1][j-1]){//
					for(int c=k;c<=i;c++)
						t+=board[c][j];
					t+=sum[i][j-1];
					if(sum[k][j]<t)
						sum[k][j]=t;
					}//
				}
				if(i<k)
				{
					if(board[i][j]+sum[i][j-1]>sum[i+1][j-1]){//
					for(int c=i;c<=k;c++)
						t+=board[c][j];
					t+=sum[i][j-1];
					if(sum[k][j]<t)
						sum[k][j]=t;
					}//
				}
			}
	}
	int j=m;
	for(int i=1;i<=n;i++)
		for(int k=n;k<=n;k++)
		{
			int t=0;
			if(i==k)
			{
				t=sum[i][j-1]+board[k][j];
				if(sum[k][j]<t)
					sum[k][j]=t;
			}
			if(i>k)
			{
				for(int c=k;c<=i;c++)
					t+=board[c][j];
				t+=sum[i][j-1];
				if(sum[k][j]<t)
					sum[k][j]=t;
			}
			if(i<k)
			{
				for(int c=i;c<=k;c++)
					t+=board[c][j];
				t+=sum[i][j-1];
				if(sum[k][j]<t)
					sum[k][j]=t;
			}
		}
	printf("%d",sum[n][m]);
	return 0;
}

/*
3 4
1 -1 3 2
2 -1 4 -1
-2 2 -3 -1
*/