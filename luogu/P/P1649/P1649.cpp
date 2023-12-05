#include <iostream>
#include <deque>
using namespace std;

/**********pair**********/
typedef struct point
{
	short x,y,dir,turn;
}p;

/* #define up 0
#define down 1
#define left 2
#define right 3 */
#define goback ((t.dir==0&&j==1)||(t.dir==1&&j==0)||(t.dir==2&&j==3)||(t.dir==3&&j==2))

const short d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
#define di t.x+d[j][0]
#define dj t.y+d[j][1]
#define dt short(t.turn+short(t.dir!=j&&t.dir!=-1))
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
	// short mt[n+1][n+1];
	p b,e;
	/**********input**********/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			// scanf("%c ",&a[i][j]);
			cin>>a[i][j];
			/* a[i][j]=getchar();
            while(a[i][j]!='A'&&a[i][j]!='B'&&a[i][j]!='.'&&a[i][j]!='x')
				a[i][j]=getchar(); */
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
	/* bool */short vis[n+1][n+1];
	fill(vis[0],vis[0]+(n+1)*(n+1),11451);
	vis[b.x][b.y]=0;
	short ans=11451;
	/**********bfs**********/
	while(!q.empty())
	{
		// l=q.size();
		t=q.front();
		q.pop_front();
		for(int j=0;j<4;j++)//dir
		{
			if(/* !vis[di][dj]&& */di>0&&dj>0&&di<=n&&dj<=n&&a[di][dj]!='x'&&!goback)
			{
				if(di==e.x&&dj==e.y)
				{
					// printf("%d",dt);
					ans=min(ans,dt);
					continue;
					// return 0;
				}
				if(dt>vis[di][dj])
				{
					continue;
				}
				else
				{
					vis[di][dj]=dt;
				}
				q.push_back({di,dj,j,dt});
			}
		}
	}
	printf("%d",(ans==11451?(-1):ans));
	// puts("-1");
	return 0;
}
/* 
3
x B x 
. . . 
x . A 
 */