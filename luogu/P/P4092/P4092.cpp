#include <iostream>
#include <vector>
using namespace std;

constexpr int N=114514;
int n,m;
vector<int> e[N];

namespace hld
{
	int dfn[N],son[N],top[N],siz[N],fa[N],dep[N],cnt=1;
	void dfs1(int u=1,int f=0)
	{
		dep[u]=dep[fa[u]=f]+(siz[u]=1);
		for(int v:e[u])if(v!=f)
		{
			dfs1(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v])son[u]=v;
		}
	}
	void dfs2(int u=1,int t=1)
	{
		dfn[u]=cnt++;
		top[u]=t;
		if(son[u])dfs2(son[u],t);
		else return;
		for(int v:e[u])if(v!=fa[u]&&v!=son[u])
		{
			dfs2(v,v);
		}
	}
}

namespace sgt
{
	int seg[N<<2];
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define mid ((l+r)>>1)
	inline int get(int x,int y)
	{
		return (hld::dep[x]>hld::dep[y]?x:y);
	}
	inline void update(int pos)
	{
		seg[pos]=get(seg[ls],seg[rs]);
	}
	void modify(int mp,int mx,int pos=1,int l=1,int r=n)
	{
		if(l==r)
		{
			seg[pos]=mx;
			return;
		}
		if(mp<=mid)modify(mp,mx,ls,l,mid);
		else modify(mp,mx,rs,mid+1,r);
		update(pos);
	}
	int query(int ql,int qr,int pos=1,int l=1,int r=n)
	{
		if(ql<=l&&r<=qr)return seg[pos];
		int res=0;
		if(ql<=mid)res=query(ql,qr,ls,l,mid);
		if(mid<qr)res=get(res,query(ql,qr,rs,mid+1,r));
		return res;
	}
}

namespace hld_op
{
	int query(int p)
	{
		int ret;
		do
		{
			ret=sgt::query(hld::dfn[hld::top[p]],hld::dfn[p]);
			p=hld::fa[hld::top[p]];
		}
		while(!ret);
		return ret;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	hld::dfs1();
	hld::dfs2();
	sgt::modify(1,1);
	char o;
	for(int i=0,p;i<m;i++)
	{
		scanf(" %c %d",&o,&p);
		if(o=='C')sgt::modify(hld::dfn[p],p);
		else printf("%d\n",hld_op::query(p));
	}
	return 0;
}