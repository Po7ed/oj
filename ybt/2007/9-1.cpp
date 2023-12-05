#include <iostream>
using namespace std;

bool book[1001][1001];
short board[1001][1001];
int ms=-(1E4+1);

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

int main()
{
	int n=0,m=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&board[i][j]);
	dfs(n,m,1,1,0);
	printf("%d",ms);
	return 0;
}

/*
3 4
1 -1 3 2
2 -1 4 -1
-2 2 -3 -1
*/