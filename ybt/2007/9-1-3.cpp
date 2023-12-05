#include <iostream>
#include <string.h>
using namespace std;

bool book[1001][1001];
short board[1001][1001];
int sum[1001][1001][2];
bool books[1001][1001];
int ms=-(1E4+1);
int dir=0,flag=0,dirr=0;

void dfs(int n,int m,int i,int j,int s,int d)
{
	if(flag==1&&d==-1){dir=-1;}//cout<<"flag==1&&d==1,dir="<<dir<<endl;
	flag++;
	
	if(books[i][j]&&sum[i][j][1]!=-1)
	{
		if(s+sum[i][j][0]>ms)
		{
			ms=s+sum[i][j][0];
		cout<<"sum!"<<ms<<" i="<<i<<",j="<<j<<endl;
			if(dir==-1){dirr=-1,dir=0;}
			//cout<<"sum!"<<ms<<" i="<<i<<",j="<<j<<"     ";
			return;
		}
		return;
	}

	
cout<<i<<" "<<j<<""<<"dir="<<dir<<endl;
	

	if(n==i&&m==j)
	{
		s+=board[i][j];
		if(s>ms)
		{
			ms=s;
			if(dir==-1){dirr=-1,dir=0;}//cout<<"s>ms,dir="<<dir<<endl;
			else if(dir==0)dirr=0;
		}

		
		//cout<<endl;
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
			sum[i][j][0]=0;
			sum[i][j][1]=0;
			books[i][j]=0;
		}
	//dfs(n,m,1,1,0);
	for(int j=m;j>0;j--)
		for(int i=n;i>0;i--)
		{
			dfs(n,m,i,j,0,0);
			sum[i][j][0]=ms;
			books[i][j]=1;
			if(dirr==-1)sum[i][j][1]=-1;
			cout<<"sum["<<i<<"]["<<j<<"] "<<ms<<" "<<sum[i][j][1]<<endl;
			ms=-(1E4+1);
			dir=0,flag=0,dirr=0;
		}
	printf("%d",sum[1][1][0]);
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