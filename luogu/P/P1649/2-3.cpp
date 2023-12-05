#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

/**********pair**********/
typedef struct point
{
	short x,y,dir,turn;
}p;

#define up 0
#define down 1
#define left 2
#define right 3

const short d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

/* #define di0 t.x-j
#define di1 t.x
#define di2 t.x+j
#define di3 t.x
#define dj0 t.y
#define dj1 t.y-j
#define dj2 t.y
#define dj3 t.y+j */

int main()
{
	short n;
	scanf("%d\n",&n);
	char a[n+1][n+1];
	p b,e;
	/**********input**********/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			// scanf("%c ",&a[i][j]);
			cin>>a[i][j];
			// a[i][j]=getchar();
			// getchar();
			if(a[i][j]=='A')
			{
				b.x=i;
				b.y=j;
				b.dir=-1;
				b.turn=0;
			}
			else if(a[i][j]=='B')
			{
				e.x=i;
				e.y=j;
				e.dir=-1;
				e.turn=-1;
			}
		}
		// getchar();
	}
	deque<p> q;
	q.push_back(b);
	// int l;
	p t;
	#define di t.x+d[j][0]
    #define dj t.y+d[j][1]
	
	bool vis[4][n+1][n+1];
	//fill(vis[0],vis[0]+4*(n+1)*(n+1),false);
	memset(vis,false,sizeof(vis));
	//bool vis1[n+1][n+1];
	//fill(vis1[0],vis1[0]+(n+1)*(n+1),false);
	//bool vis2[n+1][n+1];
	//fill(vis2[0],vis2[0]+(n+1)*(n+1),false);
	//bool vis3[n+1][n+1];
	//fill(vis3[0],vis3[0]+(n+1)*(n+1),false);
	vis[0][b.x][b.y]=true;
	vis[1][b.x][b.y]=true;	
	vis[2][b.x][b.y]=true;
	vis[3][b.x][b.y]=true;
	/**********bfs**********/
	while(!q.empty())
	{
		// l=q.size();
		t=q.front();
		q.pop_front();
		for(int j=0;j<4;j++)//dir
		{
			if(!(vis[j-1][t.x][t.y]==true&&(j==1||j==3))&&
			!(vis[j+1][t.x][t.y]==true&&(j==0||j==2))&&
			di>0&&dj>0&&di<=n&&dj<=n&&a[di][dj]!='x')
			{
				if(di==e.x&&dj==e.y)
				{
					printf("%d",t.turn+(t.dir!=j&&t.dir!=-1));
					return 0;
				}
				if(t.dir!=j&&t.dir!=-1)
				{
					q.push_back({di,dj,j,t.turn+1});
				}
				else
				{
					q.push_front({di,dj,j,t.turn});
				}
				vis[j][di][dj]=true;
			}
		}
	}
	puts("-1");
	return 0;
}