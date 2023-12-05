#include <iostream>
using namespace std;

typedef long long ll;

const ll mod=571373ll;
const size_t mn=114514ull;

int n,q;

ll a[mn];
ll seg[mn*4],tagp[mn*4],tagm[mn*4],len[mn*4];

#define ls (pos<<1)
#define rs (pos<<1|1)
#define md ((l+r)>>1)

inline void upd(int pos)
{
	seg[pos]=(seg[ls]+seg[rs])%mod;
}

void build(int pos=1,int l=1,int r=n)
{
	len[pos]=(r-l+1);
	if(l==r)
	{
		seg[pos]=a[l]%mod;
		return;
	}
	build(ls,l,md);
	build(rs,md+1,r);
	upd(pos);
	return;
}

#define mul true
#define pls false
inline void mktag(int pos,ll x,bool type)
{
	if(type)//mul
	{
		tagm[pos]*=x;
		tagp[pos]*=x;
		seg[pos]*=x;
		tagm[pos]%=mod;
		tagp[pos]%=mod;
		seg[pos]%=mod;
	}
	else//pls
	{
		tagp[pos]+=x;
		seg[pos]+=(len[pos]*x);
		tagp[pos]%=mod;
		seg[pos]%=mod;
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

void modify(int ml,int mr,ll x,bool type,int pos=1,int l=1,int r=n)
{
	if(ml<=l&&r<=mr)
	{
		mktag(pos,x,type);
		return;
	}
	pdtag(pos);//this
	if(ml<=md)
	{
		modify(ml,mr,x,type,ls,l,md);
	}
	if(md<mr)
	{
		modify(ml,mr,x,type,rs,md+1,r);
	}
	upd(pos);
}

ll query(int ql,int qr,int pos=1,int l=1,int r=n)
{
	if(ql<=l&&r<=qr)
	{
		return seg[pos]%mod;
	}
	if(tagp[pos]||tagm[pos]!=1)
	{
		pdtag(pos);
	}
	ll res=0;
	if(ql<=md)
	{
		res+=query(ql,qr,ls,l,md);
	}
	if(md<qr)
	{
		res+=query(ql,qr,rs,md+1,r);
	}
	return res%mod;
}

inline void init()
{
	fill(tagm,tagm+(mn*4),1ll);
}

int main()
{
	int m;//fvv
	scanf("%d %d %d",&n,&q,&m);
	ll opt,x,y,k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	init();
	build();
	while(q--)
	{
		scanf("%lld %lld %lld",&opt,&x,&y);
		if(opt==1)
		{
			scanf("%lld",&k);
			modify(x,y,k,mul);
		}
		else if(opt==2)
		{
			scanf("%lld",&k);
			modify(x,y,k,pls);
		}
		else if(opt==3)
		{
			printf("%lld\n",query(x,y)%mod);
		}
	}
	return 0;
}