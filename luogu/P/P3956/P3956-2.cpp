#include <iostream>
#include <queue>
#include <map>
#include <bitset>
using namespace std;

int a[114][114];
int m,n;

struct way
{
	int x,y,val;
	// bool usemagic;
	int magiccolor;
	way()
	{
		x=y=0;
		// usemagic=false;
		val=0;
		magiccolor=0;//0:none 1:red 2:blue
	}
	way(int _x,int _y,int _val,int _magiccolor)
	{
		x=_x;
		y=_y;
		val=_val;
		magiccolor=_magiccolor;
	}
	friend bool operator < (way a,way b)
	{
		return a.val>b.val;
	}
};
/* inline size_t hush(way w)
{
	// printf("%lldhush\n",(((size_t)w.magiccolor*10000ull+(size_t)(w.x-1)*(size_t)m+(size_t)w.y)*10000ull+(size_t)w.val));
	return (((size_t)w.magiccolor*10000ull+(size_t)(w.x-1)*(size_t)m+(size_t)w.y)*10000ull+(size_t)w.val);
} */

// bitset<0x3f3f3f3full> vis; 

bitset<108> vis[108];

int d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
#define dx (t.x+d[i][0])
#define dy (t.y+d[i][1])
void bfs()
{
	priority_queue<way> q;
	q.push((way){1,1,0,0});
	vis[1][1]=true;
	// vis[to({1,1,0,0})]=0;
	way t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		// printf("from%d %d\n",t.x,t.y);
		if(t.x==m&&t.y==m)
		{
			printf("%d\n",t.val);
			exit(0);
		}
		for(int i=0;i<4;i++)
		{
			if(dx>0&&dy>0&&dx<=m&&dy<=m&&(!vis[dx][dy]))
			{
				vis[dx][dy]=true;
				if(a[dx][dy]==(t.magiccolor?t.magiccolor:a[t.x][t.y]))
				{
					// printf("  sameto%d %d %d\n",dx,dy,t.val);
					q.push({dx,dy,t.val,0});
				}
				else if(a[dx][dy])
				{
					// printf("  diffto%d %d %d\n",dx,dy,t.val+1);
					q.push({dx,dy,t.val+1,0});
				}
				else if(!t.magiccolor)
				{
					// printf("  magicto%d %d %d\n",dx,dy,t.val+2);
					q.push({dx,dy,t.val+2,a[t.x][t.y]});
				}
				else
				{
					vis[dx][dy]=false;
				}
			}
			// system("pause");
		}
	}
}

int main()
{
	scanf("%d %d",&m,&n);
	int x,y,c;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c+1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			vis[i][j]=false;
		}
	}
	bfs();
	puts("-1");
	return 0;
}