#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
	int v,w;
};

struct con
{
	//dep:magic(dist. to t),lif:life,now:id
	int now,dep,lif;
	friend bool operator < (con a,con b)
	{
		return a.lif>b.lif;
	}
};

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int main()
{
	int n,m,ss,tt;
	// scanf("%d %d %d %d",&n,&m,&ss,&tt);
	n=read();
	m=read();
	ss=read();
	tt=read();
	int u,v,w;
	vector<edge> e[n+1];
	for(int i=1;i<=m;i++)
	{
		// scanf("%d %d %d",&u,&v,&w);
		u=read();
		v=read();
		w=read();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	int vis[n+1];//min lif
	fill(vis,vis+(n+1),0x3f3f3f3f);
	vis[tt]=-1;
	priority_queue<con> q;
	q.push({tt,0,0});
	con t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.now==ss)
		{
			printf("%d",t.lif);
			return 0;
		}
		for(edge to:e[t.now])
		{
			if(vis[to.v]>=t.lif+(to.w/(t.dep+1)))
			{
				vis[to.v]=t.lif+(to.w/(t.dep+1));
				q.push({to.v,t.dep+1,t.lif+(to.w/(t.dep+1))});
			}
		}
	}
	return 0;
}