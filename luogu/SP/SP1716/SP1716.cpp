#include <iostream>
using namespace std;

#define inc(_i,_b,_e) for(int _i=(_b);_i<=(_e);_i++)
#define dec(_i,_b,_e) for(int _i=(_b);_i>=(_e);_i--)
#define inc_(_i,_b,_e) for(int _i=(_b);_i<(_e);_i++)
#define dec_(_i,_b,_e) for(int _i=(_b);_i>(_e);_i--)
#define _inc(_i,_b,_e,...) for(int _i=(_b),__VA_ARGS__;_i<=(_e);_i++)
#define _dec(_i,_b,_e,...) for(int _i=(_b),__VA_ARGS__;_i>=(_e);_i--)
#define _inc_(_i,_b,_e,...) for(int _i=(_b),__VA_ARGS__;_i<(_e);_i++)
#define _dec_(_i,_b,_e,...) for(int _i=(_b),__VA_ARGS__;_i>(_e);_i--)
constexpr int N=51411,INF=0x3f3f3f3f;
int n,q;
int a[N];

struct node
{
	int pre,suf,mid,sum;
	node(int _pre=-INF,int _suf=0,int _mid=-INF,int _sum=0):
	pre(_pre),suf(_suf),mid(_mid),sum(_sum){}
	inline void operator = (int x)
	{
		pre=suf=mid=sum=x;
	}
	friend inline node operator + (node x,node y)
	{
		return {max(x.pre,x.sum+y.pre),max(y.suf,y.sum+x.suf),
		max(x.suf+y.pre,max(x.mid,y.mid)),x.sum+y.sum};
	}
};

namespace segt
{
	#define mid ((l+r)>>1)
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define root 1,1,n
	node seg[N<<2];
	inline void update(int pos)
	{
		seg[pos]=seg[ls]+seg[rs];
	}
	void build(int pos,int l,int r)
	{
		if(l==r)
		{
			seg[pos]=a[l];
			return;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
		update(pos);
	}
	void modify(int mpos,int mval,int pos,int l,int r)
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
		update(pos);
	}
	node query(int ql,int qr,int pos,int l,int r)
	{
		if(ql<=l&&r<=qr)
		{
			return seg[pos];
		}
		node res;
		if(ql<=mid)
		{
			res=res+query(ql,qr,ls,l,mid);
		}
		if(mid<qr)
		{
			res=res+query(ql,qr,rs,mid+1,r);
		}
		return res;
	}
	#undef mid
}//^ namespace segt

int main()
{
	scanf("%d",&n);
	inc(i,1,n)
	{
		scanf("%d",a+i);
	}
	segt::build(root);
	scanf("%d",&q);
	_inc(i,1,q,o,x,y)
	{
		scanf("%d %d %d",&o,&x,&y);
		if(o)
		{
			printf("%d\n",segt::query(x,y,root).mid);
		}
		else
		{
			segt::modify(x,y,root);
		}
	}
	return 0;
}