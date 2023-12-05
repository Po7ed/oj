#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> p;
#define x first
#define y second

#define di0 t.x-j
#define di1 t.x
#define di2 t.x+j
#define di3 t.x
#define dj0 t.y
#define dj1 t.y-j
#define dj2 t.y
#define dj3 t.y+j

int main()
{
	int n,m,k;
	scanf("%d %d %d\n",&n,&m,&k);
	char a[n+1][m+1];
	/**********input**********/
	for(int i=1;i<=n;i++)
	{		
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar();
		}
		getchar();
	}
	int si,sj,ti,tj;
	scanf("%d %d %d %d",&si,&sj,&ti,&tj);
	if(si==ti&&sj==tj)
	{
		puts("0");
		return 0;
	}
	/**********bfs**********/
	queue<p> q;
	q.push({si,sj});
	int l,cnt=1;
	p t;
	bool vis[n+1][m+1];
	fill(vis[0],vis[0]+(n+1)*(m+1),false);
	while(!q.empty())
	{
		l=q.size();
		for(int i=0;i<l;i++)
		{
			t=q.front();
			q.pop();
			/* if(t.x==ti&&t.y==tj)
			{
				printf("%d",cnt);
				return 0;
			} */
			for(int j=1;di0>0&&dj0>0&&di0<=n&&dj0<=m&&a[di0][dj0]!='#'&&j<=k;j++)
			{
				if(!vis[di0][dj0])
				{
					if(di0==ti&&dj0==tj)
					{
						printf("%d",cnt);
						return 0;
					}
					q.push({di0,dj0});
					vis[di0][dj0]=true;
				}
			}
			for(int j=1;di1>0&&dj1>0&&di1<=n&&dj1<=m&&a[di1][dj1]!='#'&&j<=k;j++)
			{
				if(!vis[di1][dj1])
				{
					if(di1==ti&&dj1==tj)
					{
						printf("%d",cnt);
						return 0;
					}
					q.push({di1,dj1});
					vis[di1][dj1]=true;
				}
			}
			for(int j=1;di2>0&&dj2>0&&di2<=n&&dj2<=m&&a[di2][dj2]!='#'&&j<=k;j++)
			{
				if(!vis[di2][dj2])
				{
					if(di2==ti&&dj2==tj)
					{
						printf("%d",cnt);
						return 0;
					}
					q.push({di2,dj2});
					vis[di2][dj2]=true;
				}
			}
			for(int j=1;di3>0&&dj3>0&&di3<=n&&dj3<=m&&a[di3][dj3]!='#'&&j<=k;j++)
			{
				if(!vis[di3][dj3])
				{
					if(di3==ti&&dj3==tj)
					{
						printf("%d",cnt);
						return 0;
					}
					q.push({di3,dj3});
					vis[di3][dj3]=true;
				}
			}
		}
		cnt++;
	}
	puts("-1");
	return 0;
}


