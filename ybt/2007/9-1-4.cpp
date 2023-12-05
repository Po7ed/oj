#include <iostream>
#include <string.h>
using namespace std;

bool book[1001][1001];
short board[1001][1001];
int sum1[1001][1001];
int sum2[1001][1001];
int sum3[1001][1001];
bool books[1001][1001];
int ms1=-(1E4+1),ms2=-(1E4+1),ms3=-(1E4+1);;;
int dir=0,dirr=0,k1=0,k2=0,k3=0;

void dfs(int n,int m,int i,int j,int s,int d)
{
	if(d==-1&&k1==0){dir=-1,k1=1;}//cout<<"flag==1&&d==1,dir="<<dir<<endl;
	if(d==1&&k2==0){dir=1,k2=1;}
	if(d==0&&k3==0){dir=0,k3=1;}
	
	if(books[i][j]==1&&d==1)
	{
		if(s+sum2[i][j]>ms2&&sum2[i][j]>sum3[i][j])
		{
			ms2=s+sum2[i][j];
			return;
		}
		if(s+sum3[i][j]>ms2&&sum3[i][j]>sum2[i][j])
		{
			ms2=s+sum2[i][j];
			return;
		}
		return;
	}

	if(books[i][j]&&d==0)
	{
		if((s+sum1[i][j]>ms3)&&(sum1[i][j]>sum3[i][j])&&(sum1[i][j]>sum2[i][j]))
		{
			ms3=s+sum1[i][j];
			return;
		}
		if((s+sum2[i][j]>ms3)&&(sum2[i][j]>sum3[i][j])&&(sum2[i][j]>sum1[i][j]))
		{
			ms3=s+sum2[i][j];
			return;
		}
		if((s+sum3[i][j]>ms3)&&(sum3[i][j]>sum2[i][j])&&(sum3[i][j]>sum1[i][j]))
		{
			ms3=s+sum3[i][j];
			return;
		}
		return;
	}

	if(n==i&&m==j)
	{
		s+=board[i][j];
		if(dir==-1&&s>ms1)
		{
			ms1=s;
		}
		if(dir==1&&s>ms2)
		{
			ms2=s;
		}
		if(dir==0&&s>ms3)
		{
			ms3=s;
		}
		return;
	}

	s+=board[i][j];
	book[i][j]=1;
	if(i>1&&book[i-1][j]==0)
		dfs(n,m,i-1,j,s,-1);
		
	if(i<n&&book[i+1][j]==0)
		dfs(n,m,i+1,j,s,1);
	
	if(j<m&&book[i][j+1]==0)
		dfs(n,m,i,j+1,s,0);

	book[i][j]=0;
	s-=board[i][j];
	return;
}

int main()
{
	int n=0,m=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&board[i][j]);
			book[i][j]=0;
			sum1[i][j]=0;
			sum2[i][j]=0;
			sum3[i][j]=0;
			books[i][j]=0;
		}
	//dfs(n,m,1,1,0);
	for(int j=m;j>0;j--)
		for(int i=n;i>0;i--)
		{
			dfs(n,m,i,j,0,0);
			sum1[i][j]=ms1;
			sum2[i][j]=ms2;
			sum3[i][j]=ms3;

			books[i][j]=1;

			ms1=-(1E4+1),ms2=-(1E4+1),ms3=-(1E4+1);

			dir=0,dirr=0,k1=0,k2=0,k3=0;
		}

	if(sum2[1][1]>sum3[1][1])printf("%d",sum2[1][1]);
	if(sum3[1][1]>sum2[1][1])printf("%d",sum3[1][1]);
	return 0;
}

/*
3 4
1 -1 3 2
2 -1 4 -1
-2 2 -3 -1
*/
/*
-1
-2
0
4
7
5
8
6
5
6
8
9*/