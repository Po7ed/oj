#include <iostream>
using namespace std;

typedef long long ll;

const int N=514114;
int n,m;
int a[N];

#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid ((l+r)>>1)
#define INF 0x3f3f3f3f

struct node
{
	int pre,suf,all,sum;
	node():pre(-INF),suf(-INF),all(-INF),sum(-INF){}
	inline void operator = (int x)
	{
		pre=suf=all=sum=x;
		return;
	}
	friend inline node operator + (node x,node y)
	{
		node res;
		res.sum=x.sum+y.sum;
		res.all=max(x.suf+y.pre,max(x.all,y.all));
		res.pre=max(x.pre,x.sum+y.pre);
		res.suf=max(y.suf,y.sum+x.suf);
		return res;
	}
};

node seg[N<<2];

inline void update(int pos)
{
	seg[pos]=seg[ls]+seg[rs];
}

void build(int pos=1,int l=1,int r=n)
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

void modify(int mpos,int mv,int pos=1,int l=1,int r=n)
{
	if(l==r)
	{
		seg[pos]=mv;
		return;
	}
	if(mpos<=mid)
	{
		modify(mpos,mv,ls,l,mid);
	}
	else
	{
		modify(mpos,mv,rs,mid+1,r);
	}
	update(pos);
}

node query(int ql,int qr,int pos=1,int l=1,int r=n)
{
	if(ql<=l&&r<=qr)
	{
		return seg[pos];
	}
	node res;
	if(ql<=mid&&mid<qr)
	{
		res=query(ql,qr,ls,l,mid)+query(ql,qr,rs,mid+1,r);
	}
	else if(ql<=mid)
	{
		res=query(ql,qr,ls,l,mid);
	}
	else
	{
		res=query(ql,qr,rs,mid+1,r);
	}
	return res;
}

int main()
{
	scanf("%d %d",&n,&m);
	int k,x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	build();
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&k,&x,&y);
		if(k==1)
		{
			if(x>y)
			{
				swap(x,y);
			}
			printf("%d\n",query(x,y).all);
		}
		else
		{
			modify(x,y);
		}
	}
	return 0;
}
