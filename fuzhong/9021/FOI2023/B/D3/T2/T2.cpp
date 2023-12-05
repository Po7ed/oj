#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
int a[114514],mex[114514],cur;
ll sum[311451];int rmi[311451];
int tag[311451];
bitset<114514> b;
ll ans;

#define ls (pos<<1)
#define rs (pos<<1|1)
#define md ((l+r)>>1)

inline void update(int pos)
{
	sum[pos]=sum[ls]+sum[rs];
	rmi[pos]=rmi[rs];
}

void build(int pos,int l,int r)
{
	if(l==r)
	{
		sum[pos]=(ll)mex[l];
		rmi[pos]=mex[l];
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
	rmi[pos]=x;
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
		/* if(l==r)
		{
			sum[pos]=x;
			return;
		} */
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

int srchp(int i)// a[return]<a[i]
{
	int l=1,r=n,pos=1;
	while(l!=r&&tag[pos]==-1)
	{
		if(rmi[ls]<=a[i])
		{
			r=md;
		}
		else
		{
			l=md+1;
		}
	}
	// printf("l:%d\n",l);
	if(query(1,1,n,1,1)<a[i])
	{
		return 0;
	}
	// if(query(1,1,n,n,n))
	if(l>=i)
	{
		return i-1;
	}
	return l;
}

void srch(int i)
{
	int p=0,q;
	// mex=a;
	p=q=srchp(i);
	if(1<=p&&p<(n+1))
	{
		while(q>0&&a[q]!=a[i])
		{
			q--;
		}
		q++;
		modify(1,1,n,q,p,a[i]);
		// printf("q:%d p:%d a[i]:%d\n",q,p,a[i]);
	}
	return;
}

inline void init()
{
	b.reset();
	fill(tag,tag+311451,-1);
}

void print(int I)
{
	for(int i=1;i<=I;i++)
	{
		printf("%d ",mex[i]);
	}
	puts("");
}

int main()
{
	// freopen("mex.in", "r", stdin);
	// freopen("mex.out", "w", stdout);
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=n;i>0;i--)
	{
		b[a[i]]=true;
		while(b[cur])
		{
			cur++;
		}
		mex[i]=cur;
	}
	// print(n);
	build(1,1,n);
	// ans=query(1,1,n,1,n);
	ans=(ll)sum[1];
	ll tmp;
	for(int i=n;i>1;i--)
	{
		srch(i);
		// ans+=sum[1];
		tmp=query(1,1,n,1,i-1);
		ans+=tmp;
		// print(i);
		// printf("tmp:%lld\n",tmp);
		// printf("1:%lld\n",query(1,1,n,1,1));
	}
	printf("%lld",ans);
	return 0;
}