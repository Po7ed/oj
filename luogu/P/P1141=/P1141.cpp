#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> q;

int bfs(int i,int j)
{
	q.clear();
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+2][n+2];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int i,j;
	for(int k=0;k<m;k++)
	{
		scanf("%d %d",&i,&j);
		printf("%d\n",bfs(i,j));
	}
	return 0;
}