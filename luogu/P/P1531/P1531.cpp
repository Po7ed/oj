#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

#include <cstdio>
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
}

struct _build
{
	int l,r,pos;
	bool f;
};
struct _query
{
	int l,r,pos;
	bool f;
};

#define ls(_pos) ((_pos<<1))
#define rs(_pos) ((_pos<<1)+1)

int main()
{
	int n,m;
// 	scanf("%d %d\n",&n,&m);
    n=read();
    m=read();
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
// 		scanf("%d ",a+i);
        a[i]=read();
	}
	int seg[n*4+1];
	fill(seg,seg+(4*n+1),-0x3f3f3f3f);
	vector<_build> build;
	build.push_back({1,n,1,false});
	_build _b;
	int id[n+1];
	// fill(id,id+(n+1),0);
	while(!build.empty())
	{
		_b=build.back();
		if(_b.f)
		{
			// update
			seg[_b.pos]=max(seg[ls(_b.pos)],seg[rs(_b.pos)]);
			build.pop_back();
			continue;
		}
		if(_b.l==_b.r)
		{
			seg[_b.pos]=a[_b.l];
			id[_b.l]=_b.pos;
			build.pop_back();
			continue;
		}
		int mid=_b.l+((_b.r-_b.l)>>1);
		// _b.f=true;
		build.back().f=true;
		build.push_back({mid+1,_b.r,rs(_b.pos),false});
		build.push_back({_b.l,mid,ls(_b.pos),false});
	}
	char opt;
	int x,y;
	int ret[4*n+1];
	vector<_query> query;
	_query _q;
	int now;
	for(int i=1;i<=m;i++)
	{
	   // cin>>opt;
        opt=getch();
        while(!isalpha(opt))
    	{
    		opt=getch();
    	}
	    x=read();
	    y=read();
// 		scanf("%c %d %d\n",&opt,&x,&y);
		if(opt=='Q')
		{
			fill(ret,ret+(4*n+1),-0x3f3f3f3f);
			query.push_back({1,n,1,false});
			while(!query.empty())
			{
				_q=query.back();
				if(_q.f)
				{
					ret[_q.pos]=max(ret[ls(_q.pos)],ret[rs(_q.pos)]);
					query.pop_back();
					continue;
				}
				if(x<=_q.l&&_q.r<=y)
				{
					ret[_q.pos]=seg[_q.pos];
					query.pop_back();
					continue;
				}
				// _q.f=true;
				query.back().f=true;
				int mid=_q.l+((_q.r-_q.l)>>1);
				if(mid<y)
				{
					query.push_back({mid+1,_q.r,rs(_q.pos)});
				}
				if(x<=mid)
				{
					query.push_back({_q.l,mid,ls(_q.pos)});
				}
			}
			printf("%d\n",ret[1]);
		}
		else
		{
			if(a[x]<y)
			{
				a[x]=y;
				now=id[x];
				while(now)
				{
					seg[now]=max(seg[now],a[x]);
					now>>=1;
				}
			}
		}
	}
	return 0;
}