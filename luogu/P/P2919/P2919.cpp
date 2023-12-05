#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct forsort
{
	int x,y,h;
}fs;

inline bool cmp(fs a,fs b)
{
	return (a.h==b.h?(a.x==b.x?(a.x<b.x):(a.y<b.y)):a.h>b.h);
}

typedef struct point
{
	int x,y;
}p;

int d[8][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
	{-1,-1},
	{-1,1},
	{1,-1},
	{1,1}
};
#define dx (t.x+d[i][0])
#define dy (t.y+d[i][1])

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1];
	vector<fs> v;
	// fs aa[n+1][m+1];
	// fill(*aa,*aa+(n+1)*(m+1),(fs){-1,-1,0x3f3f3f3f});
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			v.push_back({i,j,a[i][j]});
		}
	}
	sort(v.begin(),v.end(),cmp);
	bool vis[n+1][m+1];
	fill(*vis,*vis+(n+1)*(m+1),false);
	queue<p> q;
	p t;
	int cnt=0;
	for(fs s:v)
	{
		if(!vis[s.x][s.y])
		{
			vis[s.x][s.y]=true;
			q.push({s.x,s.y});
			while(!q.empty())
			{
				t=q.front();
				q.pop();
				for(int i=0;i<8;i++)
				{
					if(dx>0&&dy>0&&dx<=n&&dy<=m&&!vis[dx][dy]&&a[dx][dy]<=a[t.x][t.y])
					{
						vis[dx][dy]=true;
						q.push({dx,dy});
					}
				}
			}
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}