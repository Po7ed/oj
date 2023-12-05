#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> p;
#define a first
#define b second

#define jump(dx,dy)\
if(t.a+(dx)>0&&t.b+(dy)>0&&t.a+(dx)<=n&&t.b+(dy)<=m&&!vis[t.a+(dx)][t.b+(dy)])\
{\ 
	q.push({t.a+(dx),t.b+(dy)});vis[t.a+(dx)][t.b+(dy)]=true;\
}

int main()
{
	int n,m,x,y;
	scanf("%d %d %d %d",&n,&m,&x,&y);
	bool vis[n+1][m+1];
	int dis[n+1][m+1];
	fill(vis[0],vis[0]+(n+1)*(m+1),false);
	fill(dis[0],dis[0]+(n+1)*(m+1),-1);
	vis[x][y]=true;
	// dis[x][y]=0;
	queue<p> q;
	q.push({x,y});
	p t;
	int l,c=0;
	while(!q.empty())
	{
		l=q.size();
		for(int i=0;i<l;i++)
		{
			t=q.front();
			q.pop();
			dis[t.a][t.b]=c;
			jump(-2,-1);
			jump(-2,1);
			jump(-1,-2);
			jump(-1,2);
			jump(2,-1);
			jump(2,1);
			jump(1,-2);
			jump(1,2);
		}
		c++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",dis[i][j]);
		puts("");
	}
	return 0;
}