#include <iostream>
using namespace std;
const int M=614514;

int n,m,q;
int a[M],na[M],pa[M],aa[M],b[M],nb[M],pb[M]/* ,ab[M] */;

struct segtree// Simplified
{
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define mid ((l+r)>>1)
	int ma[M],mi[M],ms[M];
	int ql,qr,*ar;
	bool nf;
	inline void upd(int pos)
	{
		mi[pos]=min(mi[ls],mi[rs]);
		ma[pos]=max(ma[ls],ma[rs]);
		if(abs(ms[ls])<abs(ms[rs])||
		abs(ms[ls])==abs(ms[rs])&&(nf&&ms[ls]<=0||!nf&&ms[rs]>=0))
		{
			ms[pos]=ms[ls];
		}
		else
		{
			ms[pos]=ms[rs];
		}
	}
	void build(int l,int r,int pos)
	{
		if(l==r)
		{
			mi[pos]=ma[pos]=ms[pos]=ar[l];
			return;
		}
		build(l,mid,ls);
		build(mid+1,r,rs);
		upd(pos);
	}
	int query_min(int l,int r,int pos)
	{
		if(ql<=l&&r<=qr)
		{
			return mi[pos];
		}
		int res=0x3f3f3f3f;
		if(ql<=mid)
		{
			res=min(res,query_min(l,mid,ls));
		}
		if(mid<qr)
		{
			res=min(res,query_min(mid+1,r,rs));
		}
		return res;
	}
	int query_max(int l,int r,int pos)
	{
		if(ql<=l&&r<=qr)
		{
			return ma[pos];
		}
		int res=-0x3f3f3f3f;
		if(ql<=mid)
		{
			res=max(res,query_max(l,mid,ls));
		}
		if(mid<qr)
		{
			res=max(res,query_max(mid+1,r,rs));
		}
		return res;
	}
	int query_abs(int l,int r,int pos)
	{
		if(ql<=l&&r<=qr)
		{
			return ms[pos];
		}
		int res=0x3f3f3f3f;
		if(ql<=mid)
		{
			res=query_abs(l,mid,ls);
		}
		if(mid<qr)
		{
			int t=query_abs(mid+1,r,rs);
			if(abs(res)>abs(t)||abs(res)==abs(t)&&(nf&&t<=0||!nf&&t>=0))
			{
				res=t;
			}
		}
		return res;
	}
};

int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		na[i]=na[i-1]+(a[i]<0);
		pa[i]=pa[i-1]+(a[i]>=0);
		aa[i]=abs(a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",b+i);
		nb[i]=nb[i-1]+(b[i]<0);
		pb[i]=pb[i-1]+(b[i]>=0);
		// ab[i]=abs(b[i]);
	}
	segtree ta,tb,taa/* ,tab */;
	ta.ar=a;ta.build(1,n,1);
	tb.ar=b;tb.build(1,m,1);
	taa.ar=aa;taa.build(1,n,1);
	// tab.ar=ab;tab.build(1,m,1);
	int l1,r1,l2,r2;
	long long qa,qb,tb1,tb2,ta1,ta2,mul;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		ta.ql=l1;ta.qr=r1;
		tb.ql=l2;tb.qr=r2;
		taa.ql=l1;taa.qr=r1;
		if(na[l1-1]<na[r1]&&pa[l1-1]<pa[r1])
		{
			if(nb[l2-1]<nb[r2]&&pb[l2-1]<pb[r2])
			{
				tb1=tb.query_max(1,m,1);// pos
				tb2=tb.query_min(1,m,1);// neg
				ta.nf=true;ta1=ta.query_abs(1,n,1);//neg?
				ta.nf=false;ta2=ta.query_abs(1,n,1);// pos?
				if(abs(ta1)==abs(ta2))
				{
					if(ta1<0)
					{
						mul=ta1*tb1;
					}
					else
					{
						mul=ta1*tb2;
					}
					if(ta2<0)
					{
						mul=max(mul,ta2*tb1);
					}
					else
					{
						mul=max(mul,ta2*tb2);
					}
					printf("%lld\n",mul);
					continue;
				}
				if(abs(ta1)<abs(ta2))
				{
					qa=ta1;
					if(qa<0)
					{
						qb=tb1;
					}
					else
					{
						qb=tb2;
					}
				}
				else
				{
					qa=ta2;
					if(qa<0)
					{
						qb=tb1;
					}
					else
					{
						qb=tb2;
					}
				}
			}
			else if(nb[l2-1]==nb[r2])
			{
				qa=ta.query_max(1,n,1);
				qb=tb.query_min(1,m,1);
			}
			else
			{
				qa=ta.query_min(1,n,1);
				qb=tb.query_max(1,m,1);
			}
		}
		else if(na[l1-1]==na[r1])
		{
			if(nb[l2-1]<nb[r2])
			{
				qa=ta.query_min(1,n,1);
				qb=tb.query_min(1,m,1);
			}
			else
			{
				qa=ta.query_max(1,n,1);
				qb=tb.query_min(1,m,1);
			}
		}
		else
		{
			if(pb[l2-1]<pb[r2])
			{
				qa=ta.query_max(1,n,1);
				qb=tb.query_max(1,m,1);
			}
			else
			{
				qa=ta.query_min(1,n,1);
				qb=tb.query_max(1,m,1);
			}
		}
		printf("%lld\n",qa*qb);
	}
	return 0;
}