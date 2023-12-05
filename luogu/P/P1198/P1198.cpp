#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=214514;
int m,n;
ll p,t;

namespace segt
{
	#define mid ((l+r)>>1)
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define root 1,1,N
	ll seg[N<<2];
	inline void update(int pos)
	{
		seg[pos]=max(seg[ls],seg[rs]);
	}
	void modify(int mpos,ll mval,int pos,int l,int r)
	{
		if(l==r)
		{
			seg[pos]=mval;
			return;
		}
		if(mpos<=mid)
		{
			modify(mpos,mval,ls,l,mid);
		}
		else
		{
			modify(mpos,mval,rs,mid+1,r);
		}
		return update(pos);
	}
	ll query(int ql,int qr,int pos,int l,int r)
	{
		if(ql<=l&&r<=qr)
		{
			return seg[pos];
		}
		ll res=-0x3f3f3f3f3f3f3f3f;
		if(ql<=mid)
		{
			res=max(res,query(ql,qr,ls,l,mid));
		}
		if(mid<qr)
		{
			res=max(res,query(ql,qr,rs,mid+1,r));
		}
		return res;
	}
}

#define inchar(c) do c=getchar();while(c!='A'&&c!='Q');

int main()
{
	scanf("%d %lld",&m,&p);
	char o;
	ll x;
	for(int i=1;i<=m;i++)
	{
		inchar(o)
		scanf("%lld",&x);
		if(o=='Q')
		{
			printf("%lld\n",t=segt::query(n-(int)x+1,n,root));
		}
		else
		{
			++n;
			segt::modify(n,(t+x)%p,root);
		}
	}
	return 0;
}