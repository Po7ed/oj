#include <iostream>
#include <deque>
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
	#define di (t.x+d[j][0])
    #define dj (t.y+d[j][1])
	#define dt (t.turn+(t.dir!=j&&t.dir!=-1))
	
	/* bool */short vis[n+1][n+1];
	fill(vis[0],vis[0]+(n+1)*(n+1),/* false */11451);
	// vis[b.x][b.y]=true;
	vis[b.x][b.y]=0;
	/**********bfs**********/
	while(!q.empty())
	{
		// l=q.size();
		t=q.front();
		q.pop_front();
		for(int j=0;j<4;j++)//dir
		{
			if(vis[di][dj]>=dt&&di>0&&dj>0&&di<=n&&dj<=n&&a[di][dj]!='x')
			{
				if(di==e.x&&dj==e.y)
				{
					vis[di][dj]=dt;
					continue;
					// printf("%d",dt);
					// return 0;
				}
				/* if(t.dir!=j&&t.dir!=-1)
				{
					q.push_back({di,dj,j,t.turn+1});
					// printf("(%d,%d) ",di,dj);
				}
				else
				{
					q.push_front({di,dj,j,t.turn});
				} */
				q.push_front({di,dj,j,dt});
				vis[di][dj]=dt;
				// printf("(%d,%d,%d) ",di,dj,t.turn+short(t.dir!=j&&t.dir!=-1));
			}
		}
	}
	printf("%d",(vis[e.x][e.y]==11451?-1:vis[e.x][e.y]));
	// puts("-1");
	return 0;
}


/* 
3
x x A
. . .
. B .
 */
/* 
3
. . .
x B .
x . A
 */
/* 
3
. B x
x . .
x . A
 */
/* 
3
. x x
B . .
x . A
 */