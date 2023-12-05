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
	// vis[to({1,1,0,0})]=0;
	way t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.x==m&&t.y==m)
		{
			printf("%d\n",t.val);
			exit(0);
		}
		printf("%d %d\n",t.x,t.y);
		for(int i=0;i<4;i++)
		{
			if(dx>0&&dy>0&&dx<=m&&dy<=m&&!vis[dx][dy])
			{
				if(a[dx][dy]==(t.magiccolor?t.magiccolor:a[t.x][t.y]))
				{
					if(!vis[hush({dx,dy,t.val,0})])
					{
						vis[hush({dx,dy,t.val,0})]=true;
						printf("%lldon\n",hush({dx,dy,t.val,0}));
						q.push({dx,dy,t.val,0});
					}
				}
				else if(a[dx][dy])
				{
					if(!vis[hush({dx,dy,t.val+1,0})])
					{
						vis[hush({dx,dy,t.val+1,0})]=true;
						printf("%lldon\n",hush({dx,dy,t.val+1,0}));
						q.push({dx,dy,t.val+1,0});
					}
				}
				else if(t.magiccolor)
				{
					if(!vis[hush({dx,dy,t.val+2,a[t.x][t.y]})])
					{
						vis[hush({dx,dy,t.val+2,a[t.x][t.y]})]=true;
						printf("%lldon\n",hush({dx,dy,t.val+2,a[t.x][t.y]}));
						q.push({dx,dy,t.val+2,a[t.x][t.y]});
					}
				}
			}
			system("pause");
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
	bfs();
	puts("-1");
	return 0;
}