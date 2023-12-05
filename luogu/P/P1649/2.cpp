#include <iostream>
#include <deque>
using namespace std;

/**********pair**********/
typedef struct point
{
	int x,y,dir,turn;
}p;

#define up 0
#define down 1
#define left 2
#define right 3

const int d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
#define di t.x+d[j][0]
#define dj t.y+d[j][1]
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
	int n;
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
	// bool vis[n+1][n+1];
	short vis[n+1][n+1];
	fill(vis[0],vis[0]+(n+1)*(n+1),11451);
	/**********bfs**********/
	while(!q.empty())
	{
		// l=q.size();
		t=q.front();
		q.pop_front();
		if(vis[t.x][t.y]<t.turn)
		    continue;
		vis[t.x][t.y]=t.turn;
		for(int j=0;j<4;j++)//dir
		{
			if(di>0&&dj>0&&di<=n&&dj<=n&&a[di][dj]!='x')
			{
				if(di==e.x&&dj==e.y)
				{
					// printf("%d",t.turn+(t.dir!=j&&t.dir!=-1));
					vis[di][dj]=t.turn+(t.dir!=j&&t.dir!=-1);
					// return 0;
				}
				if(t.dir!=j&&t.dir!=-1)
				{
					q.push_back({di,dj,j,t.turn+1});
// printf("*%d %d %d %d\n",di,dj,j,t.turn+1);
				}
				else
				{
					q.push_front({di,dj,j,t.turn});
// printf("*%d %d %d %d\n",di,dj,j,t.turn);
				}
			}
		}
	}
	printf("%d",(vis[e.x][e.y]!=11451?vis[e.x][e.y]:-1));
	// puts("-1");
	return 0;
}
/* 
3
x B x 
. . . 
x x A 
 */
/* 
3
x x x
x . A
B . x
 */
