#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
int a[114514],mex[114514],cur;
ll sum[311451];
int tag[311451];
bitset<114514> b;
ll ans;

#define ls (pos<<1)
#define rs (pos<<1|1)
#define md ((l+r)>>1)

inline void update(int pos)
{
	sum[pos]=sum[ls]+sum[rs];
}

void build(int pos,int l,int r)
{
	if(l==r)
	{
		sum[pos]=(ll)a[l];
		return;
	}
	int mid=md;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(pos);
}

inline void mktag(int pos,int len,int x)
{
	sum[pos]=len*x;
	tag[pos]=x;
}

inline void pdtag(int pos,int l,int r)
{
	int mid=md;
	mktag(ls,mid-l+1,tag[pos]);
	mktag(rs,r-mid,tag[pos]);
	tag[pos]=-1;
}

void modify(int pos,int l,int r,int ml,int mr,int x)
{
	if(ml<=l&&r<=mr)
	{
		mktag(pos,r-l+1,x);
		return;
	}
	int mid=md;
	if(ml<=mid)
	{
		modify(ls,l,mid,ml,mr,x);
	}
	if(mid<mr)
	{
		modify(rs,mid+1,r,ml,mr,x);
	}
	update(pos);
	return;
}

ll query(int pos,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		return (ll)sum[pos];
	}
	if(tag[pos]!=-1)
	{
		pdtag(pos,l,r);
	}
	int mid=md;
	ll ret=0;
	if(ql<=mid)
	{
		ret=query(ls,l,mid,ql,qr);
	}
	if(mid<qr)
	{
		ret+=query(rs,mid+1,r,ql,qr);
	}
	return ret;
}

bool cmp(int val,int ele)
{
	return val>ele;
}

void srch(int x)
{
	int p=0,q;
	// mex=a;
	p=q=upper_bound(mex+1,mex+(n+1),x,cmp)-mex-1;
	if(1<=p&&p<(n+1))
	{
		while(q>0&&a[q]!=x)
		{
			q--;
		}
		q++;
		modify(1,1,n,q,p,x);
	}
	return;
}

inline void init()
{
	b.reset();
	fill(tag,tag+311451,-1);
}

int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	build(1,1,n);
	int m;
	scanf("%d",&m);
	int l,r,c,opt;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&opt,&l,&r,&c);
		if(opt)
			modify(1,1,n,l,r,c);
		else
			printf("%lld\n",query(1,1,n,l,r));
		for(int i=1;i<=32;i++)
		{
			printf("%d %lld %d\n",i,sum[i],tag[i]);
		}
	}
	return 0;
}