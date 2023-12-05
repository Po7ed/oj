#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <bitset>
using namespace std;

#include <cstdio>
#include <cctype>
const int BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
inline char getch()
{
    if(is == it)
        it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
    return is == it ? EOF : *is++;
}
inline int read()
{
    int res = 0, ch = getch();
    while(!(isdigit(ch)) and ch != EOF)
        ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return res;
}

const int N=1145141,K=11451;
vector<int> e[N];

int a[K];
int n,m,k;

struct ufs
{
	int f[N];/* ufs(){iota(f,f+N,0);} */
	inline void Reinit(){iota(f,f+n+1,0);}
	int Find(int x){return (f[x]==x?x:f[x]=Find(f[x]));}
	inline bool Union(int x,int y){x=Find(x),y=Find(y);if(x!=y)return f[y]=x;return false;}
};

struct node
{
	int id,d;
	friend inline bool operator < (node x,node y)
	{
		return x.d>y.d;
	}
};
int dis[N];
void dijkstra()
{
	fill(dis,dis+N,0x3f3f3f3f);
	priority_queue<node> q;
	for(int i=1;i<=k;i++)
	{
		q.push({a[i],0});
		dis[a[i]]=0;
	}
	node t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		#define u t.id
		if(dis[u]!=t.d)continue;
		for(int v:e[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}
		}
		#undef u
	}
}

ufs s;
bool check(int x)
{
	s.Reinit();
	for(int u=1;u<=n;u++)
	{
		if(dis[u]>x)continue;
		for(int v:e[u])
		{
			if(dis[v]>x||v>u)continue;
			if(!s.Union(u,v))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	// scanf("%d %d %d",&n,&m,&k);
	n=read(),m=read(),k=read();
	int x,y;
	for(int i=1;i<=m;i++)
	{
		// scanf("%d %d",&x,&y);
		x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=k;i++)
	{
		// scanf("%d",a+i);
		a[i]=read();
	}
	dijkstra();
	int l=0,r=n,mid,ans=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	if(ans==-1)
	{
		puts("Poor D!");
	}
	else
	{
		printf("%d",ans);
	}
	return 0;
}