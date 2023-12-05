#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int que[100001][2];
bool book[100001];
int head=1,tail=1;
int link[100001][2];
int path[100001][2];

void bfs(int index,int step,int n)
{
	que[tail][0]=index;
	que[tail][1]=step;
	tail++;
	for(int i=1;i<=n;i++)
	{
		if(link[i][0]==que[tail-1][0])
		{
			bfs(link[i][1],step+1,n);
		}
		if(link[i][1]==que[tail-1][0])
		{
			bfs(link[i][0],step+1,n);
		}
	}
	return;
}

int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	memset(link,0,sizeof(link));
	memset(path,0,sizeof(path));
	for(int c=1;c<=m;c++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		link[c][0]=u;link[c][1]=v;
	}
	for(int c=0;c<q;c++)
	{
		int a,l;
		scanf("%d %d",&a,&l);
		memset(que,-1,sizeof(que));
		for(int i=1;i<=m;i++)
		{
			if(link[i][0]==a)
			{
				bfs(link[i][1],1,n);
			}
			if(link[i][1]==a)
			{
				bfs(link[i][0],1,n);
			}
		}
	}
	return 0;
}