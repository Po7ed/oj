#include <iostream>
using namespace std;

typedef long long ll;
const int N=114514;

int n,q;
ll mod;
int a[N];

struct segtree// 依托答辩
{
	ll seg[N<<2],tagm[N<<2],tagp[N<<2],len[N<<2];
	#define ls (pos<<1)
	#define rs ((pos<<1)|1)
	#define mid ((l+r)>>1)
	segtree(){fill(seg,seg+(N<<2),0),fill(tagm,tagm+(N<<2),1),fill(tagp,tagp+(N<<2),0);}
	inline void mktagm(int pos,ll x){tagm[pos]*=x,tagm[pos]%=mod;
	tagp[pos]%=mod,tagp[pos]*=x;seg[pos]*=x,seg[pos]%=mod;}
	inline void mktagp(int pos,ll x){tagp[pos]+=x,tagp[pos]%=mod;
	seg[pos]+=(len[pos]*x),seg[pos]%=mod;}
	inline void deltag(int pos){tagm[pos]=1,tagp[pos]=0;}
	inline void pdtag(int pos){mktagm(ls,tagm[pos]),mktagm(rs,tagm[pos]);
	mktagp(ls,tagp[pos]),mktagp(rs,tagp[pos]);deltag(pos);}
	inline void update(int pos){seg[pos]=(seg[ls]+seg[rs])%mod;}
	void build(int pos=1,int l=1,int r=n){len[pos]=r-l+1;
	if(l==r){seg[pos]=a[l]%mod;return;}build(ls,l,mid),build(rs,mid+1,r);update(pos);}
	int ql,qr;ll query(int pos=1,int l=1,int r=n)
	{if(ql<=l&&r<=qr)return seg[pos]%mod;ll res=0;pdtag(pos);
	if(ql<=mid)res+=query(ls,l,mid);if(mid<qr)res+=query(rs,mid+1,r);return res%mod;}
	int ml,mr;ll x;bool mul;void modify(int pos=1,int l=1,int r=n)
	{if(ml<=l&&r<=mr){(mul?mktagm(pos,x):mktagp(pos,x));return;}pdtag(pos);
	if(ml<=mid)modify(ls,l,mid);if(mid<mr)modify(rs,mid+1,r);update(pos);}
	#undef ls
	#undef rs
	#undef mid
}t;

int main()
{
	scanf("%d %lld",&n,&mod);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	t.build();
	scanf("%d",&q);
	int opt;
	for(int i=0;i<q;i++)
	{
		scanf("%d",&opt);
		if(opt==3)
		{
			scanf("%d %d",&t.ql,&t.qr);
			printf("%lld\n",t.query()%mod);
		}
		else
		{
			scanf("%d %d %lld",&t.ml,&t.mr,&t.x);
			t.mul=(opt==1);
			t.modify();
		}
		// for(int j=1;j<=3*n;j++)
		// printf("*%d %lld %lld %lld\n",j,t.seg[j],t.tagp[j],t.tagm[j]);
	}
	return 0;
}