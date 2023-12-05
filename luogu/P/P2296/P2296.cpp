#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

const int mn=11451,mm=214514;
int n,m;

vector<int> e[mn],_e[mn];

queue<int> q;
bitset<mn> vis,can;
void bfs(int s)
{
	q.push(s);
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		vis[u]=true;
		for(int v:_e[u])
		{
			if(!vis[v])
			{
				q.push(v);
			}
		}
	}
}

inline void ban()
{
	can.set();
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			for(int fr:_e[i])
			{
				can[fr]=false;
				#ifndef ONLINE_JUDGE
				printf("ban:%d\n",fr);
				#endif
			}
		}
	}
}

struct node
{
	int id,d;
	friend bool operator < (node x,node y)
	{
		return x.d<y.d;
	}
};

int dis[mn];
priority_queue<node> pq;
void dijkstra(int s)
{
	fill(dis,dis+mn,0x3f3f3f3f);
	dis[s]=0;
	pq.push({s,0});
	node t;
	while(!pq.empty())
	{
		t=pq.top();
		pq.pop();
		#define u t.id
		#define d t.d
		if(dis[u]!=d)
		{
			continue;
		}
		for(int v:e[u])
		{
			if(can[v]&&dis[v]>d+1)
			{
				dis[v]=d+1;
				pq.push({v,dis[v]});
			}
		}
		#undef u
		#undef d
	}
}
#ifndef ONLINE_JUDGE
#include <ctime>
#endif

int main()
{
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		_e[v].push_back(u);
	}
	int s,t;
	scanf("%d %d",&s,&t);
	#ifndef ONLINE_JUDGE
	time_t beg=clock();
	#endif
	bfs(t);
	ban();
	dijkstra(s);
	printf("%d",(dis[t]==0x3f3f3f3f?-1:dis[t]));
	#ifndef ONLINE_JUDGE
	printf("\n\n---------------\n%lldms.",clock()-beg);
	#endif
	return 0;
}