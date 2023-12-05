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

bitset<N> vis;
queue<int> q;
ufs s;
bool check(int x)
{
	s.Reinit();
	vis.reset();
	for(int i=1;i<=k;i++)
	{
		q.push(a[i]);
		vis[a[i]]=true;
	}
	int u,siz,dep=0;
	while(!q.empty()&&dep<=x)
	{
		dep++;
		siz=q.size();
		while(siz--)
		{
			u=q.front();
			q.pop();
			for(int v:e[u])
			{
				if(!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	while(!q.empty())
	{
		vis[q.front()]=false;
		q.pop();
	}
	for(int u=1;u<=n;u++)
	{
		if(!vis[u])continue;
		for(int v:e[u])
		{
			if(!vis[v]||v>u)continue;
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
