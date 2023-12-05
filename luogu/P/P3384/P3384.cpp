#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;// !long long!
const int N=114514;
int n,m,r;
ll p;
int a[N];

vector<int> e[N];

#define DFT 1,n,1

namespace segt
{
	void modify(int,int,ll,int,int,int);
	ll query(int,int,int,int,int);
}

namespace mod
{
	ll plus(ll a,ll b){return((a+=b)>=p?a-=p:a);}
}//^ namespace mod

namespace dcmp
{
	//* init
	int dep[N],siz[N],fa[N],son[N];
	void init(int u=r,int f=r)
	{
		dep[u]=dep[f]+1;
		fa[u]=f;
		siz[u]=1;
		for(int v:e[u])
		{
			if(v!=f)
			{
				init(v,u);
				siz[u]+=siz[v];
				if(siz[son[u]]<siz[v])
				{
					son[u]=v;
				}
			}
		}
	}
	int top[N],dfn[N],rnk[N],dfncnt=1;
	void dfs(int u=r,int t=r)
	{
		top[rnk[dfn[u]=dfncnt++]=u]=t;
		if(son[u])
		{
			dfs(son[u],t);
		}
		for(int v:e[u])
		{
			if(v!=fa[u]&&v!=son[u])//! or program will inf roop
			{
				dfs(v,v);
			}
		}
	}
	//* options
	void modify(int x,int y,ll z)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])//! top[]!!!
			{
				swap(x,y);
			}
			segt::modify(dfn[top[x]],dfn[x],z,DFT);
			x=fa[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		segt::modify(dfn[x],dfn[y],z,DFT);
	}
	ll query(int x,int y)
	{
		ll res=0;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])//! top[]!!!
			{
				swap(x,y);
			}
			res=mod::plus(res,segt::query(dfn[top[x]],dfn[x],DFT));
			x=fa[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		return mod::plus(res,segt::query(dfn[x],dfn[y],DFT));
	}
	void modify(int x,ll z)
	{
		segt::modify(dfn[x],dfn[x]+siz[x]-1,z,DFT);
	}
	ll query(int x)
	{
		return segt::query(dfn[x],dfn[x]+siz[x]-1,DFT);
	}
}//^ namespace dcmp

namespace segt
{
	#define mid ((l+r)>>1)
	#define ls (pos<<1)
	#define rs ((pos<<1)|1)//! ???">>"???
	ll seg[N<<2],tag[N<<2];
	inline void update(int pos)
	{
		seg[pos]=mod::plus(seg[ls],seg[rs]);
	}
	void build(int l=1,int r=n,int pos=1)
	{
		if(l==r)
		{
			seg[pos]=a[dcmp::rnk[l]]%p;
			return;
		}
		build(l,mid,ls);
		build(mid+1,r,rs);
		update(pos);
	}
	inline void mktag(int pos,ll mo,int len)
	{
		tag[pos]=mod::plus(tag[pos],mo);
		seg[pos]=mod::plus(seg[pos],1ll*len*mo%p);//! mod p
	}
	inline void pdtag(int pos,int l,int r)
	{
		mktag(ls,tag[pos],mid-l+1);
		mktag(rs,tag[pos],r-mid);
		tag[pos]=0;
	}
	void modify(int ml,int mr,ll mo,int l,int r,int pos)
	{
		if(ml<=l&&r<=mr)
		{
			mktag(pos,mo,r-l+1);
			return;
		}
		pdtag(pos,l,r);
		if(ml<=mid)
		{
			modify(ml,mr,mo,l,mid,ls);
		}
		if(mid<mr)
		{
			modify(ml,mr,mo,mid+1,r,rs);
		}
		update(pos);
	}
	ll query(int ql,int qr,int l,int r,int pos)
	{
		if(ql<=l&&r<=qr)
		{
			return seg[pos];
		}
		pdtag(pos,l,r);
		ll res=0;
		if(ql<=mid)
		{
			res=mod::plus(res,query(ql,qr,l,mid,ls));
		}
		if(mid<qr)
		{
			res=mod::plus(res,query(ql,qr,mid+1,r,rs));
		}
		return res;
	}
}//^ namespace segt

int main()
{
	// freopen("P3384_4.in","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%d %d %d %lld",&n,&m,&r,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dcmp::init();
	dcmp::dfs();
	segt::build();
	ll z;
	for(int i=1,o,x,y;i<=m;i++)
	{
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d %d %lld",&x,&y,&z);
			dcmp::modify(x,y,z%p);
		}
		else if(o==2)
		{
			scanf("%d %d",&x,&y);
			printf("%lld\n",dcmp::query(x,y));
		}
		else if(o==3)
		{
			scanf("%d %lld",&x,&z);
			dcmp::modify(x,z%p);
		}
		else
		{
			scanf("%d",&x);
			printf("%lld\n",dcmp::query(x));
		}
	}
	return 0;
}