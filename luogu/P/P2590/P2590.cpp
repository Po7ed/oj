#include <iostream>
#include <vector>
using namespace std;

constexpr int N=31145,INF=0x3f3f3f3f;
int n,q;
vector<int> e[N];
int a[N];

int merge(int a,int b,bool typ){return typ?a+b:max(a,b);}
int init(bool typ){return typ?0:-INF;}

namespace hld
{
	int son[N],top[N],dfn[N],rnk[N],siz[N],fa[N],dep[N],cnt=0;
	void dfs1(int u=1,int f=0)
	{
		dep[u]=dep[f]+1;
		siz[u]=1;
		fa[u]=f;
		for(int v:e[u])if(v!=f)
		{
			dfs1(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v])
			{
				son[u]=v;
			}
		}
	}
	void dfs2(int u=1,int t=1)
	{
		rnk[dfn[u]=++cnt]=u;
		top[u]=t;
		if(son[u])dfs2(son[u],t);
		else return;
		for(int v:e[u])if(v!=fa[u]&&v!=son[u])
		{
			dfs2(v,v);
		}
	}
}//^ namespace hld

namespace sgt
{
	int sum[N<<2],ma[N<<2];
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define mid ((l+r)>>1)
	inline void update(int pos)
	{
		sum[pos]=sum[ls]+sum[rs];
		ma[pos]=max(ma[ls],ma[rs]);
	}
	void build(int pos=1,int l=1,int r=n)
	{
		if(l==r){sum[pos]=ma[pos]=a[hld::rnk[l]];return;}
		build(ls,l,mid);
		build(rs,mid+1,r);
		return update(pos);
	}
	#define qmax false
	#define qsum true
	void modify(int mp,int mv,int pos=1,int l=1,int r=n)
	{
		if(l==r){sum[pos]=ma[pos]=mv;return;}
		if(mp<=mid)modify(mp,mv,ls,l,mid);
		else modify(mp,mv,rs,mid+1,r);
		return update(pos);
	}
	int query(int ql,int qr,bool typ,int pos=1,int l=1,int r=n)
	{
		// printf("%d %d\n",l,r);
		// system("pause>nul");
		if(ql<=l&&r<=qr)return (typ?sum[pos]:ma[pos]);
		int res=init(typ);
		if(ql<=mid)res=query(ql,qr,typ,ls,l,mid);
		if(mid<qr)res=merge(res,query(ql,qr,typ,rs,mid+1,r),typ);
		return res;
	}
}//^ namespace sgt

namespace hld
{
	int query(int u,int v,bool typ)
	{
		int res=init(typ);
		while(top[u]!=top[v])
		{
			if(dep[top[u]]>dep[top[v]])swap(u,v);
			res=merge(res,sgt::query(dfn[top[v]],dfn[v],typ),typ);
			v=fa[top[v]];
		}
		if(dep[u]>dep[v])swap(u,v);
		return merge(res,sgt::query(dfn[u],dfn[v],typ),typ);
	}
}//^ namespace hld

char o[8];

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	hld::dfs1();
	hld::dfs2();
	sgt::build();
	scanf("%d",&q);
	int u,v;
	while(q--)
	{
		scanf(" %s %d %d",o,&u,&v);
		if(o[0]=='C')sgt::modify(hld::dfn[u],v);
		else printf("%d\n",hld::query(u,v,(o[1]=='M')?qmax:qsum));
	}
	return 0;
}
