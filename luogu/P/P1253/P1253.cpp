#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=1145141;
constexpr ll INF=0x3f3f3f3f3f3f3f3fll;
int n,q;
ll a[N];

namespace segt
{
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define mid ((l+r)>>1)
	ll seg[N<<2],tp[N<<2],tf[N<<2]/* ,len[N<<2] */;//! tf:fill
	inline void init()
	{
		fill(seg,seg+(N<<2),-INF);
		fill(tf,tf+(N<<2),INF);
	}
	inline void update(int pos)
	{
		seg[pos]=max(seg[ls],seg[rs]);
	}
	void build(int pos=1,int l=1,int r=n)
	{
		// len[pos]=r-l+1;
		if(l==r)
		{
			seg[pos]=a[l];
			return;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
		update(pos);
	}
	#define pls true
	#define fil false
	inline void mktag(int pos,ll x,bool typ)
	{
		if(typ==pls)
		{
			(tf[pos]^INF?tf[pos]:tp[pos])+=x;
			seg[pos]+=x;
		}
		else//^ fill
		{
			tf[pos]=x;
			tp[pos]=0;
			seg[pos]=x;
		}
	}
	inline void pdtag(int pos)
	{
		if(tf[pos]^INF)// if fill hav tag
		{
			mktag(ls,tf[pos],fil);
			mktag(rs,tf[pos],fil);
			tf[pos]=INF;
		}
		if(tp[pos])//todo del 'else'
		{
			mktag(ls,tp[pos],pls);
			mktag(rs,tp[pos],pls);
			tp[pos]=0;
		}
	}
	void modify(int ml,int mr,ll x,bool typ,int pos=1,int l=1,int r=n)
	{
		if(ml<=l&&r<=mr)return mktag(pos,x,typ);
		pdtag(pos);
		if(ml<=mid)modify(ml,mr,x,typ,ls,l,mid);
		if(mid<mr)modify(ml,mr,x,typ,rs,mid+1,r);
		update(pos);
	}
	ll res;
	ll query(int ql,int qr,int pos=1,int l=1,int r=n)
	{
		if(ql<=l&&r<=qr)return seg[pos];
		pdtag(pos);
		res=-INF;
		if(ql<=mid)res=query(ql,qr,ls,l,mid);
		if(mid<qr)res=max(res,query(ql,qr,rs,mid+1,r));
		// update(pos);
		return res;
	}
}//^ namespace segt

int main()
{
	freopen("P1253_2.in","r",stdin);
	freopen("my.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){scanf("%lld",a+i);if(a[i]==9225)printf("**%d\n",i);}
	int o,l,r;
	ll x;
	segt::init();
	segt::build();
	while(q--)
	{
		scanf("%d %d %d",&o,&l,&r);
		if(o==3)printf("%lld\n",segt::query(l,r));
		else
		{
			scanf("%lld",&x);
			if(o==1)segt::modify(l,r,x,fil);
			else segt::modify(l,r,x,pls);
		}
	}
	return 0;
}