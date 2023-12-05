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

/* #include <cstdio>
#include <cctype>
const int BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
inline char getch(){
    if(is == it)
        it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
    return is == it ? EOF : *is++;
}
inline int read(){
    int res = 0, neg = 0, ch = getch();
    while(!(isdigit(ch) or ch == '-') and ch != EOF)
        ch = getch();
    if(ch == '-')
        neg = 1, ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return neg ? -res : res;
} */
int main()
{
	int n,m,ss,tt;
	scanf("%d %d %d %d",&n,&m,&ss,&tt);
	// n=read();
	// m=read();
	// ss=read();
	// tt=read();
	int u,v,w,maw=-0x3f3f3f3f;
	vector<edge> e[n+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		// u=read();
		// v=read();
		// w=read();
		maw=max(w,maw);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	priority_queue<con> q;
	q.push({tt,0,0});
	con t;
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