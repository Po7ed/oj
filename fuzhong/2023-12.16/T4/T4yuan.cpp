#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int N=414514,mod=998244353;
int n,m,q;
vector<int> e[N];

namespace force
{
	int a[N];
	void solve()
	{
		int o,u,p;
		for(int i=1;i<=q;i++)
		{
			scanf("%d %d",&o,&u);
			if(o==3)
			{
				printf("%d\n",a[u]);
			}
			else
			{
				scanf("%d",&p);
				if(o==1)
				{
					(a[u]+=p)%=mod;
					for(int v:e[u])
					{
						(a[v]+=p)%=mod;
					}
				}
				else
				{
					(a[u]*=p)%=mod;
					for(int v:e[u])
					{
						(a[v]*=p)%=mod;
					}
				}
			}
		}
	}
}// namespace force

namespace tree
{
	int bfn[N],fa[N],beg[N],end[N];
	struct node
	{
		int u,f;
	};
	void bfs()
	{
		queue<node> q;
		q.push({1,0});
		int u,f,cnt=0;
		bfn[1]=++cnt;
		while(!q.empty())
		{
			u=q.front().u;
			f=q.front().f;
			fa[u]=f;
			q.pop();
			for(int v:e[u])if(v!=f)
			{
				bfn[v]=++cnt;
				q.push({v,u});
				if(!beg[u])beg[u]=bfn[v];
				end[u]=bfn[v];
			}
		}
	}
	
	int seg[N<<2],tagm[N<<2],tagp[N<<2],len[N<<2];
	void init()
	{
		return fill(tagm,tagm+(N<<2),1);
	}
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define mid ((l+r)>>1)
	inline void update(int pos)
	{	
		seg[pos]=(seg[ls]+seg[rs])%mod;
	}
	void build(int pos=1,int l=1,int r=n)
	{
		len[pos]=r-l+1;
		if(l==r)
		{
			return;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	#define mul true
	#define pls false
	inline void mktag(int pos,int x,bool typ)
	{
		if(typ==mul)//mul
		{
			tagm[pos]=int(1ll*tagm[pos]*x%mod);
			tagp[pos]=int(1ll*tagp[pos]*x%mod);
			seg [pos]=int(1ll*seg [pos]*x%mod);
		}
		else//pls
		{
			(tagp[pos]+=x)%=mod;
			seg[pos]=1ll*(1ll*seg[pos]+1ll*(len[pos]*x))%mod;
		}
	}
	inline void pdtag(int pos)
	{
		mktag(ls,tagm[pos],mul);
		mktag(ls,tagp[pos],pls);
		mktag(rs,tagm[pos],mul);
		mktag(rs,tagp[pos],pls);
		tagp[pos]=0;
		tagm[pos]=1;
	}
	void modify(int ml,int mr,int mv,bool typ,int pos=1,int l=1,int r=n)
	{
//		printf("pos%d l%d r%d (ml%d mr%d mv%d)\n",pos,l,r,ml,mr,mv);
		if(ml<=l&&r<=mr)
		{
			return mktag(pos,mv,typ);
		}
		pdtag(pos);
		if(ml<=mid)
		{
			modify(ml,mr,mv,typ,ls,l,mid);
		}
		if(mid<mr)
		{
			modify(ml,mr,mv,typ,rs,mid+1,r);
		}
		update(pos);
	}
	int query(int qp,int pos=1,int l=1,int r=n)
	{
		if(l==r)
		{
			return seg[pos];
		}
		if(tagp[pos]||tagm[pos]-1)pdtag(pos);
		if(qp<=mid)
		{
			return query(qp,ls,l,mid);
		}
		else
		{
			return query(qp,rs,mid+1,r);
		}
	}
	void solve()
	{
		init();
		build();
//		puts("end build()");
		int o,u,p;
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d:%d ",i,bfn[i]);
//		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d %d",&o,&u);
//			printf("%d\n",i);
			if(o==3)
			{
				printf("%d\n",query(bfn[u]));
			}
			else
			{
				scanf("%d",&p);
				if(o==1)
				{
					if(fa[u])modify(bfn[fa[u]],bfn[fa[u]],p,pls);
//					puts("modify father end;");
					modify(bfn[u],bfn[u],p,pls);
					modify(beg[u],end[u],p,pls);
				}
				else
				{
					if(fa[u])modify(bfn[fa[u]],bfn[fa[u]],p,mul);
					modify(bfn[u],bfn[u],p,mul);
					modify(beg[u],end[u],p,mul);
				}
			}
		}
		return;
	}
}// namespace tree

int main()
{
	freopen("garden.in","r",stdin);
	freopen("garden.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n<=1000)// force
	{
		force::solve();
	}
	else// tree
	{
		tree::bfs();
		tree::solve();
	}
	return 0;
 } 