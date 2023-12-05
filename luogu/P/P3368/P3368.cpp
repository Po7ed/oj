#include <iostream>
using namespace std;
#define mn 500001

typedef long long ll;

int n,m;
ll a[mn],d[4*mn],tag[4*mn];

void Build(int l=1,int r=n,int root=1)
{
	tag[root]=0;
	if(l==r)
	{
		d[root]=a[l];
		return;
	}
	int mid=l+((r-l)>>1);
	Build(l,mid,2*root);
	Build(mid+1,r,2*root+1);
	d[root]=d[2*root]+d[2*root+1];
	return;
}

ll query(int l,int r,int x,int pos)
{
	if(l==r)
	{
		return d[pos];
	}
	int mid=l+((r-l)>>1);
	if(tag[pos])
	{
		if(l!=r)
		{
			d[2*pos]+=(mid-l+1)*tag[pos];
			d[2*pos+1]+=(r-mid)*tag[pos];
			tag[2*pos]+=tag[pos];
			tag[2*pos+1]+=tag[pos];
		}
		tag[pos]=0;
	}
	if(x<=mid)
	{
		return query(l,mid,x,2*pos);
	}
	if(mid<x)
	{
		return query(mid+1,r,x,2*pos+1);
	}
	return 114514;
}

ll query(int l,int r,int ql,int qr,int pos)
{
	if(ql<=l&&r<=qr)
	{
		return d[pos];
	}
	int mid=l+((r-l)>>1);
	ll s=0;
	if(tag[pos])
	{
		if(l!=r)
		{
			d[2*pos]+=(mid-l+1)*tag[pos];
			d[2*pos+1]+=(r-mid)*tag[pos];
			tag[2*pos]+=tag[pos];
			tag[2*pos+1]/* aaaaaaaarrrrrrrrrrgggghhh */+=tag[pos];
		}
		tag[pos]=0;
	}
	/* if(tag[pos])
	{
		d[2*pos]+=(mid-l+1)*tag[pos];
		d[2*pos+1]+=(r-mid)*tag[pos];
		tag[2*pos]+=tag[pos];
		tag[2*pos+1]=tag[pos];
		tag[pos]=0;
	} */
	if(ql<=mid)
	{
		s+=query(l,mid,ql,qr,2*pos);
	}
	if(mid<qr)
	{
		s+=query(mid+1,r,ql,qr,2*pos+1);
	}
	return s;
}

void modify(int l,int r,int x,int pos,ll k)
{
	d[pos]+=k;
	if(l==r)
	{
		a[l]+=k;
		return;
	}
	int mid=l+((r-l)>>1);
	if(x<=mid)
	{
		modify(l,mid,x,2*pos,k);
	}
	if(mid<x)
	{
		modify(mid+1,r,x,2*pos+1,k);
	}
	return;
}

void modify(int l,int r,int ml,int mr,int pos,ll k)
{
	// d[pos]+=k;
	if(ml<=l&&r<=mr)
	{
		d[pos]+=(r-l+1)*k;
		tag[pos]+=k;
		return;
	}
	int mid=l+((r-l)>>1);
	// if(l>r)return;
	if(tag[pos])
	{
		if(l!=r)
		{
			d[2*pos]+=(mid-l+1)*tag[pos];
			d[2*pos+1]+=(r-mid)*tag[pos];
			tag[2*pos]+=tag[pos];
			tag[2*pos+1]+=tag[pos];
		}
		tag[pos]=0;
	}
	if(ml<=mid)
	{
		modify(l,mid,ml,mr,2*pos,k);
	}
	if(mid<mr)
	{
		modify(mid+1,r,ml,mr,2*pos+1,k);
	}
	d[pos]=d[2*pos]+d[2*pos+1];
	return;
}

int main()
{
	freopen("P3368_2.in","r",stdin);
	scanf("%d %d",&n,&m);
	// int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	Build(/* 1,n,1 */);
	// build(1,n,1);
	// puts("Build Done");
	int x,y,opt;
	ll k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt-1)
		{
			scanf("%d",&x);
			printf("%lld\n",query(1,n,x,1));
		}
		else
		{
			scanf("%d %d %lld",&x,&y,&k);
			modify(1,n,x,y,1,k);
			// update(x,y,k,1,n,1);
		}
	}
	return 0;
}