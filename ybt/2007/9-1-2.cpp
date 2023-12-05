#include <iostream>
#include <string.h>
using namespace std;

bool book[1001][1001];
short board[1001][1001];
int sum[1001][1001];
bool books[1001][1001];
int ms=-(1E4+1);

void dfs(int n,int m,int i,int j,int s)
{
	if(books[i][j])
	{
		if(s+sum[i][j]>ms)
		{
			ms=s+sum[i][j];
			cout<<"sum!"<<ms<<" "<<i<<","<<j<<endl;
			return;
		}
		return;
	}
	//cout<<i<<" "<<j<<endl;
	if(n==i&&m==j)
	{
		s+=board[i][j];
		if(s>ms)
		{
			ms=s;
		}
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

int main()
{
	int n=0,m=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&board[i][j]);
			book[i][j]=0;
			sum[i][j]=0;
			books[i][j]=0;
		}
	//dfs(n,m,1,1,0);
	for(int j=m;j>0;j--)
		for(int i=n;i>0;i--)
		{
			dfs(n,m,i,j,0);
			sum[i][j]=ms;
			books[i][j]=1;
			cout<<ms<<endl;
			ms=-(1E4+1);
		}
	printf("%d",sum[1][1]);
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