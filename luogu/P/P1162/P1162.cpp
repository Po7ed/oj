#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> p;
#define i first
#define j second

int n;

int d[4][2]=
{
	{-1,0},
	{ 1,0},
	{0,-1},
	{0, 1}
};
#define di t.i+d[k][0]
#define dj t.j+d[k][1]

vector<p> f;
bool vis[31][31];
bool is1[31][31];
bool bfs(int x,int y/* ,int (*b)[(n+2)] */)
{
	queue<p> q;
	f.push_back({x,y});
	// b[x][y]=2;
	q.push({x,y});
	p t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		vis[t.i][t.j]=true;
		for(int k=0;k<4;k++)
		{
			if(di>0&&di<=n&&dj>0&&dj<=n)
			{
				if(!vis[di][dj]&&!is1[di][dj])
				{
					f.push_back({di,dj});
					q.push({di,dj});
					/* b[di][dj]=2; */
				}
			}
			else
			{
				// if()
				f.clear();
				return false;
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	int a[n+2][n+2]/* ,b[n+2][n+2] */;
	// fill(vis[0],vis[0]+31*31,false);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			vis[i][j]=(bool)a[i][j];
			is1[i][j]=(bool)a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(/* !vis[i][j]&& */!a[i][j])
			{
				// memcpy(b[0],a[0],(n+2)*(n+2));
				if(bfs(i,j))
				{
					for(p t:f)
					{
						a[t.i][t.j]=2;
					}
					for(int i=1;i<=n;i++)
					{
						for(int j=1;j<=n;j++)
						{
							printf("%d ",a[i][j]);
						}
						puts("");
					}
				}
			}
		}
	}
	return 0;
}