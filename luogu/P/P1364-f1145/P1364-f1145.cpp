#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int G[101][3];
int w[101];
bool vis[101];
int bfs(int r)
{
	int c=0;
	queue<pair<int,int>> q;
	memset(vis,0,sizeof(vis));
	q.push(make_pair(r,0));
	vis[r]=true;
	while(!q.empty())
	{
		pair<int,int> t=q.front();
		q.pop();
		for(int i=0;i<=2;i++)
		{
			if(G[t.first][i]&&(!vis[G[t.first][i]]))
			{
				q.push(make_pair(G[t.first][i],t.second+1));
				vis[G[t.first][i]]=true;
				c+=(w[G[t.first][i]]*(t.second+1));
			}
		}
	}
	return c;
}
int main()
{
	int n,m=0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&w[i],&G[i][1],&G[i][2]);
		G[G[i][1]][0]=i;G[G[i][2]][0]=i;
	}	
	for(int i=1;i<=n;i++)
	{
		m=min(m,bfs(i));
	}
	printf("%d",m);
	return 0;
}
/*
9
21 2 3
91 4 5
12 0 0
9 6 0
5 7 0
97 0 0
76 8 0
7 9 0
99 0 0
*/