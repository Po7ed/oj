#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace io
{
	constexpr int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	inline char getch()
	{
		if (is == it)
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
		return (is == it) ? EOF : *is++;
	}
	inline int getint()
	{
		int res = 0;
		bool neg = false;
		char ch = getch();
		while (!(isdigit(ch) or ch == '-') and ch != EOF)
			ch = getch();
		if (ch == '-')
			neg = true, ch = getch();
		while (isdigit(ch))
			res = res * 10 + (ch - '0'), ch = getch();
		return neg ? -res : res;
	}
}

constexpr int N=200000,INF=0x3f3f3f3f;

struct edge{int v,w;};

struct node
{
	//dep:magic(dist. to t),lif:life,now:id
	int now,dep,lif;
	friend inline bool operator < (node a,node b)
	{return a.lif>b.lif;}
};
int n,m,ss,tt;
vector<edge> e[N];

int main()
{
	// scanf("%d %d %d %d",&n,&m,&ss,&tt);
	n=io::getint();
	m=io::getint();
	ss=io::getint();
	tt=io::getint();
	int u,v,w,maw=-INF;
	for(int i=1;i<=m;i++)
	{
		// scanf("%d %d %d",&u,&v,&w);
		u=io::getint();
		v=io::getint();
		w=io::getint();
		maw=max(w,maw);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	priority_queue<node> q;
	q.push({tt,0,0});
	node t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.now==ss||t.dep>maw)
		{
			printf("%d",t.lif);
			return 0;
		}
		for(edge to:e[t.now])
		{
			q.push({to.v,t.dep+1,t.lif+(to.w/(t.dep+1))});
		}
	}
	return 0;
}